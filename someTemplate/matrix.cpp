#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=2;
struct Matrix {
	double a[2][2];
	void clear(double p) {
		a[0][0]=0;
		a[0][1]=1;
		a[1][0]=1-p;
		a[1][1]=p;
	}
	friend Matrix operator * (const Matrix &a,const Matrix &b) {
		Matrix c;
		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++)
				c.a[i][j]=0;
		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++)
				for (int k=0;k<N;k++)
					c.a[i][j]+=a.a[i][k]*b.a[k][j]; //注意这样访问b较慢，cache命中率低，要交换顺序
		return c;
	}
	Matrix pow(int n) {
		Matrix c,x=*this;
		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++)
				c.a[i][j]=0;
		for (int i=0;i<N;i++) c.a[i][i]=1;
		while (n) {
			if (n&1) c=c*x;
			x=x*x;
			n>>=1;
		}
		return c;
	}
};

int n,a[11];
double p;
double dp[2];
Matrix c;

int main() {
	int i,cur;
	while (scanf("%d%lf",&n,&p)!=EOF) {
		for (i=0;i<n;i++) scanf("%d",&a[i]);
		a[n+1]=-1;
		sort(a,a+n);
		dp[0]=0;
		dp[1]=1;
		c.clear(p);
		cur=1;
		for (i=0;i<n;i++) {
			if (a[i]!=a[n+1]) {
				Matrix tmp=c.pow(a[i]-cur);
				dp[0]=tmp.a[0][0]*dp[0]+tmp.a[0][1]*dp[1];
				dp[1]=0;
				cur=a[i];
			}
		}
		printf("%.7f\n",dp[0]*(1-p));
	}
	return 0;
}

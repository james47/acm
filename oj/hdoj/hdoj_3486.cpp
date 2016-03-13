#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int n, k, tot, maxi;
int d[200100][20];
void init()
{		
	for (int j = 1; (1 << j) < n; j++){
		int t = (1 << j) - 1;
		for (int i = 0; i+t < n; i++){
			d[i][j] = max(d[i][j-1], d[i+(1<<(j-1))][j-1]);
		}
	}
}
inline int rmq(int a, int b)
{
	int l = int(log(double(b-a+1))/log(2.0));
	return max(d[a][l], d[b+1-(1<<l)][l]);
}
/*
int cal(int len)
{
	int sum = 0;
	for (int i = 0; i+len-1 < n; i += len){
		int j = i+len-1;
		sum += rmq(i, j);
		if (sum > k) break;
	}
	return sum;
}
*/
int main()
{
	while(scanf("%d %d", &n, &k) && n >= 0 && k >= 0)
	{
		tot = maxi = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &d[i][0]);
			tot += d[i][0];
			maxi = max(maxi, d[i][0]);
		}
		if (tot <= k){
			puts("-1");
			continue;
		}
		init();
		int ans = n;
		for (int i = max(1, k/maxi); i < n; i++){
			//int tmp = cal(n/i);
			int len = n/i;
			int tmp = 0;
			for (int j = 1; j <= i; j++){
				tmp += rmq((j-1)*len, j*len-1);
				if (tmp > k) break;
			}
			if (tmp > k){
				ans = i;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

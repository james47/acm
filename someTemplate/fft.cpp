#include<cstdio>
#include<complex>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1<<21;
const double PI = acos(-1.0);

struct Complex{
	double x, y;
	Complex(double xx = 0, double yy = 0){ x = xx, y = yy; }
	friend Complex operator + (const Complex &a, const Complex &b){
		return Complex(a.x+b.x, a.y+b.y);
	}
	friend Complex operator - (const Complex &a, const Complex &b){
		return Complex(a.x-b.x, a.y-b.y);
	}
	friend Complex operator * (const Complex &a, const Complex &b){
		return Complex(a.x*b.x-a.y*b.y, a.y*b.x+b.y*a.x);
	}
};
typedef Complex CD;
//typedef complex<double> CD;
//注释部分采用stl的complex，会慢些

//oper==1 DFT oper==-1 IDFT
void FFT(CD* a, int n, int oper){		// n must be 2^exp
	for (int i = 1, j = 0; i < n; i++){
		for (int s = n; j^=s>>=1, ~j&s;);
		if (i < j) swap(a[i], a[j]);
	}
	for (int m = 1; m < n; m <<= 1){
		int m2 = m<<1;
		double p = PI/m*oper;
		CD w = CD(cos(p), sin(p));
		for (int i = 0; i < n; i += m2){
			CD unit = 1;
			for (int j = 0; j < m; j++){
				CD &x = a[i+j+m], &y = a[i+j], t = unit*x;
				x = y-t;
				y = y+t;
				//unit *= w;
				unit = unit * w;
			}
		}
	}
	//if (oper == -1) for (int i = 0; i < n; i++) a[i] /= n;
	if (oper == -1) for (int i = 0; i < n; i++) a[i].x /= n;
}

//传入多项式A[]和B[]的系数，长度分别为la与lb(最高次项为x^la-1与x^lb-1)
//返回两者乘积多项式C[]的系数，长度lc = la+lb-1。 复杂度O(nlogn)
void Polynomial_Mul(int* A, int la, int* B, int lb, int* C, int& lc){
	int n = 1; while(n < la + lb) n <<= 1;
	static CD a[N], b[N];
	for (int i = 0; i < n; i++){	//高次补0
		a[i] = i<la? A[i]: 0;
		b[i] = i<lb? B[i]: 0;
	}
	FFT(a, n, 1);		//DFT
	FFT(b, n, 1);
	//for (int i = 0; i < n; i++) a[i] *= b[i];
	for (int i = 0; i < n; i++) a[i] = a[i] * b[i];
	FFT(a, n, -1);		//IDFT
	lc = la + lb - 1;
	//for (int i = 0; i < lc; i++) C[i] = (int)(a[i].real() + 0.5);
	for (int i = 0; i < lc; i++) C[i] = (int)(a[i].x + 0.5);
	//if a[i].x <= 0 有可能需要 C[i] = (int)(a[i].x - 0.5)
}

int main()
{
	return 0;
}

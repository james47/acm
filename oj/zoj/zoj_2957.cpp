#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int n;
double x, ans;
double f[100];
int main()
{
	while(scanf("%d%lf", &n, &x) != EOF)
	{
		f[48] = 0;
		f[47] = 1;
		for (int i = 47; i > 0; i--)
			f[i-1] = (2*i + 1) * f[i] / x - f[i+1];
		ans = f[n] * sin(x) / x / f[0];
		int cnt = 0;
		while(fabs(ans) < 1.0)
			ans *= 10.0, cnt++;
		printf("%.3lf*10^-%d\n", ans, cnt);
	}
	return 0;
}

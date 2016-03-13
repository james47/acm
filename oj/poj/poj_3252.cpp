#include<cstdio>
#include<cstring>
using namespace std;

int a, b;
int c[40][40];
int d[40];
void init()
{
	for (int i = 0; i <= 32; i++){
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = c[i][j-1] * (i-j+1) / j;
	}
}
int cal(int x)
{
	if (x == -1) return 0;
	int ret = 1, len = 0;
	while(x){
		d[len++] = x & 1;
		x >>= 1;
	}
	for (int i = 1; i < len; i++)
		for (int j = 0; j+1 <= i/2; j++)
			ret += c[i-1][j];
	int zero = 0, one = 1;
	for (int i = len-2; i >= 0; i--){
		if (d[i]){
			zero++;
			for (int j = 0; j <= i && j+one <= zero+(i-j); j++)
				ret += c[i][j];
			zero--;
			one++;
		}
		else zero ++;
	}
	if (zero >= one) ret++;
	return ret;
}
int main()
{
	init();
	while(scanf("%d %d", &a, &b) != EOF)
	{
		printf("%d\n", cal(b) - cal(a-1));
	}
	return 0;
}

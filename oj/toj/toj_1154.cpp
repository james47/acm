#include<cstdio>
#include<cstring>
using namespace std;

int n, m;
int f(int n, int m)
{
	int ret = 0;
	for (int i = 1; i < n; i++)
		for (int j = i+1; j < n; j++){
			int t = i * i + j * j + m;
			if (t % (i*j) == 0) ret ++;
		}
	return ret;
}
int main()
{
	int cas = 0;
	while(scanf("%d %d", &n, &m))
	{
		if (n == 0 && m == 0) break;
		printf("Case %d: %d\n", ++cas, f(n, m));
	}
	return 0;
}

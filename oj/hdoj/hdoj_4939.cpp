#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<ctime>
#include<string>
using namespace std;

int T, n, x, y, z, t;
long long f[1510][1510];
int main()
{
	int cas = 0;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d %d %d", &n, &x, &y, &z, &t);
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= i; j++){	
				long long tmp = f[i-1][j] + (long long)y * (i-1-j) * (t + j*z);
				if (j > 0) tmp = max(tmp, f[i-1][j-1] + (long long)y * (i-j) * (t + (j-1)*z));
				f[i][j] = tmp;
				if (i == j) f[i][j] = 0;
			}
		long long ans = 0;
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= i; j ++){
				long long tmp = f[i][j] + (long long)(x + (i-j) * y) * (t + j*z) * (n - i);
				if (tmp > ans) ans = tmp;
			}
		}
		cas ++;
		printf("Case #%d: %lld\n", cas, ans);
	}
	return 0;
}


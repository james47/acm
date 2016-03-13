#include<cstdio>
#include<cstring>
using namespace std;

bool dp[1200][15];
int ct[1200][15];
int p[1200];
bool a[1200];
int n, k, size;
void create_prime()
{
	memset(a, true, sizeof(a));
	size = 0;
	for (int i = 2; i <= 1120; i++){
		if (a[i]) p[size++] = i;
		for (int j = 2*i; j <= 1120; j += i)
			a[j] = false;
	}
}
int main()
{
	create_prime();
	while(scanf("%d%d", &n, &k) && (n + k))
	{
		memset(dp, 0, sizeof(dp));
		dp[0][0] = true;
		ct[0][0] = 1;
		for (int i = 0; i < size; i++){
			int tmp = p[i];
			if (tmp > n) break;
			for (int j = n; j >= tmp; j--)
				for (int kk = 1; kk <= k; kk++) if (dp[j-tmp][kk-1]){
					if (!dp[j][kk]){
						dp[j][kk] = true;
						ct[j][kk] = ct[j-tmp][kk-1];
					}
					else
						ct[j][kk] += ct[j-tmp][kk-1];
			}
		}
		if (!dp[n][k]) ct[n][k] = 0;
		printf("%d\n", ct[n][k]);
	}
	return 0;
}

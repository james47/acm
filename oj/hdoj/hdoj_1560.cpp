#include<cstdio>
#include<cstring>
using namespace std;

int n, cas;
int dp[6*6*6*6*6*6*6*6 + 100],
    ha[6*6*6*6*6*6*6*6 + 100];
char str[10][10];
char ch[4] = {'A', 'T', 'C', 'G'};
int min(int a, int b)
{
	if (a < b) return a; else return b;
}
void F(int x)
{
	if (ha[x] == cas) return;
	int xx = x, p[10], op[10];
	for (int i = n - 1; i >= 0; i--)
	{
		op[i] = p[i] = xx % 6;
		xx /= 6;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < n; j++)
			if (p[j] > 0 && str[j][p[j] - 1] == ch[i]) p[j] --;
		int sum = 0;
		for (int j = 0; j < n; j++)
			sum = sum * 6 + p[j];
		for (int j = 0; j < n; j++)
			p[j] = op[j];
		if (sum == x) continue;
		F(sum);
		//dp[x] = dp[x]==-1? dp[sum]+1: min(dp[x], dp[sum]+1);
		if (ha[x] != cas)
		{
			dp[x] = dp[sum] + 1;
			ha[x] = cas;
		}
		else
		{
			dp[x] = min(dp[sum] + 1, dp[x]);
			//ha[x] = cas;
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	cas = 0;
	memset(ha, -1, sizeof(ha));
	while (T--)
	{
		scanf("%d", &n); getchar();
		//memset(dp, -1, sizeof(dp));
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str[i]);
			sum = sum * 6 + strlen(str[i]);
		}
		dp[0] = 0;
		F(sum);
		printf("%d\n", dp[sum]);
		cas++;
	}
	return 0;
}

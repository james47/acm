#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char str[110];
int dp[110][110];
bool match(int i, int j)
{
	if (str[i] == '(' && str[j] == ')') return true;
	if (str[i] == '[' && str[j] == ']') return true;
	return false;
}
int main()
{
	while(scanf("%s", str))
	{
		if (str[0] == 'e') break;
		int len = strlen(str);
		memset(dp, 0, sizeof(dp));
		for (int l = 1; l < len; l++){
			for (int i = 0; i < len; i++){
				int j = i + l;
				if (j >= len) break;
				if (match(i, j)) dp[i][j] = max(dp[i][j], dp[i+1][j-1] + 2);
				for (int k = i; k < j; k++)
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j]);
			}
		}
		printf("%d\n", dp[0][len-1]);
	}
	return 0;
}

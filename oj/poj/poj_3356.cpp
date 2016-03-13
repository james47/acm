#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int lx, ly, oo;
char x[1100], y[1100];
int dp[1100][1100];
bool same(int i, int j)
{
	if (x[i] == y[j]) return true;
	else return false;
}
int main()
{
	while(scanf("%d %s %d %s", &lx, x, &ly, y) != EOF)
	{
		memset(dp, 127, sizeof(dp));
		oo = dp[0][0];
		dp[0][0] = 0;
		for (int i = 0; i <= lx; i++)
			for (int j = 0; j <= ly; j++){
				if (i > 0 && j > 0 && dp[i-1][j-1] != oo)
					dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1 - same(i-1, j-1)); //Change
				if (i > 0 && dp[i-1][j] != oo)
					dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);		     //Deletion of x or Insertion of y
				if (j > 0 && dp[i][j-1] != oo)
					dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);		     //Insertion of x or Deletion of y
			//	printf("%d %d %d\n", i, j, dp[i][j]);
			}
		printf("%d\n", dp[lx][ly]);
	}
	return 0;
}

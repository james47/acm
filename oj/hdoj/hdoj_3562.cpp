#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int, int> > p;
int n, x, y, z;
int dp[1100][1100];
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		p.clear();
		for (int i = 4; i <= n; i++){
			scanf("%d %d", &x, &y);
			p.push_back(make_pair(x, y));
		}
		int ans = 0;
		for (int i = p.size()-1; i+1; i --){
			x = p[i].first, y = p[i].second, z = i+4;
			ans = max(ans, dp[x][y] + dp[x][z] + dp[y][z] + 3);
			dp[x][y] = max(dp[x][y], dp[x][z] + dp[y][z] + 1);
			dp[y][x] = dp[x][y];
		}
		ans = max(ans, dp[1][2] + dp[1][3] + dp[2][3] + 3);
		printf("%d\n", ans);
	}
	return 0;
}

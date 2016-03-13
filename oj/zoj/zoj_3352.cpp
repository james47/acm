#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int n, m, x, y, a, b;
vector<int> E[55];
int dp[55][55][210], ct[55][55][210];
int s[55];
int dfs(int w, int b, int k)
{
	if (ct[w][b][100+k] != -1) return dp[w][b][100+k];
	dp[w][b][100+k] = -21474836; 
	if (E[w].empty() && E[b].empty()){
		dp[w][b][100+k] = -k;
		return -k;
	}
	int &ret = dp[w][b][100+k]; int &cnt = ct[w][b][100+k];
	vector<int>::iterator i;
	for (i = E[w].begin(); i != E[w].end(); i ++){
		int tmp = -dfs(*i, b, k + s[*i]);
		if (tmp > ret){
			ret = tmp;
			cnt = 1;
		}
		else if (tmp == ret) cnt++;
	}
	for (i = E[b].begin(); i != E[b].end(); i ++){
		int tmp = -dfs(w, *i, k - s[*i]);
		if (tmp > ret){
			ret = tmp;
			cnt = 1;
		}
		else if (tmp == ret) cnt++;
	}
	return ret;
}
int main()
{
	while(scanf("%d %d %d %d", &n, &m, &x, &y) != EOF)
	{
		for (int i = 0; i < n; i++){
			scanf("%d", &s[i]);
			E[i].clear();
		}
		for (int i = 0; i < m; i++){
			scanf("%d %d", &a, &b);
			E[a].push_back(b);
		}
		memset(ct, -1, sizeof(ct));
		dfs(x, y, 1);
		printf("%d %d\n", dp[x][y][101], ct[x][y][101]);
	}
	return 0;
}

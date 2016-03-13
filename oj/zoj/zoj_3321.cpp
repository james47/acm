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

int n, m, x, y;
bool e[30][30];
bool vis[30];
bool dfs(int x, int dep)
{
	for (int i = 1; i <= n; i++)
		if (e[x][i] && !vis[i]){
			vis[i] = true;
			return dfs(i, dep+1);
		}
		else if (e[x][i] && i == 1 && dep == n) return true;
	return false;
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		memset(e, 0, sizeof(e));
		for (int i = 0; i < m; i++){
			scanf("%d %d", &x, &y);
			e[x][y] = true;
			e[y][x] = true;
		}
		if (n != m){
			printf("NO\n");
			continue;
		}
		if (n < 3){
			printf("NO\n");
			continue;
		}
		memset(vis, 0, sizeof(vis));
		vis[1] = true;
		if (dfs(1, 1))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}


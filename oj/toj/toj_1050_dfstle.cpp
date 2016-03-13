#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int T, p, n;
bool vis[310];
vector<int> v[110];
bool dfs(int dep)
{
	if (dep == p) return true;
	for (int i = 0; i < v[dep].size(); i++){
		int id = v[dep][i];
		if (!vis[id]){
			vis[id] = true;
			if (dfs(dep+1)) return true;
			vis[id] = false;
		}
	}
	return false;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &p, &n);
		for (int i = 0; i < p; i++){
			int t, id;
			scanf("%d", &t);
			v[i].clear();
			for (int j = 0; j < t; j++){
				scanf("%d", &id);
				v[i].push_back(id);
			}
		}
		memset(vis, 0, sizeof(vis));
		bool flag = dfs(0);
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 500010;
struct P{ int v, id; } p[maxn];
bool cmp(P a, P b){ return a.v < b.v; }
int n, dp[maxn], m[maxn];
vector<int> v[maxn];
int main()
{
	while(scanf("%d", &n) != EOF){
		for (int i = 0; i < n; i++){
			scanf("%d", &p[i].v);
			p[i].id = i+1;
			v[i].clear();
		} 
		sort(p, p+n, cmp);
		for (int i = 0; i < n; i++) m[p[i].id] = i;
		int U, V, ans = 0;
		for (int i = 1; i < n; i++){
			scanf("%d %d", &U, &V);
			int uu = m[U], vv = m[V];
			if (p[uu].v > p[vv].v) v[vv].push_back(uu);
			else v[uu].push_back(vv);
		}
		for (int i = n-1; i >= 0; i--){
			dp[i] = 1;
			for (int j = 0, len = (int)v[i].size(); j < len; j++)
				dp[i] += dp[v[i][j]];
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int N = (int)1e5 + 10;
struct edge{
	int n, v;
} e[N*2];
int n, m, dfn, esize;
int a[N], sum[N], en[N];
void addedge(int u, int v){
	e[esize].v = v;
	e[esize].n = en[u];
	en[u] = esize++;
}
int l[N*2], r[N*2];
//vector<int> e[N];
char buf[10];
void dfs(int cur, int fa){
	l[cur] = dfn ++;
//	for (int i = 0, len = (int)e[cur].size(); i < len; i++){
	for (int t = en[cur]; t != -1; t = e[t].n){
		int v = e[t].v;//e[cur][i];
		if (v != fa) dfs(v, cur);
	}
	r[cur] = dfn ++;
}
int query(int x){
	if (x == 0) return 0;
	int ret = 0;
	for (int i = x; i > 0; i -= (i&-i))
		ret += sum[i];
	return ret;
}
void add(int x, int v){
	for (int i = x; i <= n*2; i += (i&-i))
		sum[i] += v;
}
int main()
{
	scanf("%d", &n);
	/*
	for (int i = 1; i <= n; i++){
		e[i].clear();
	}
	*/
	esize = 0;
	memset(en, -1, sizeof(int)*(n+1));
	int u, v;
	for (int i = 1; i < n; i++){
		scanf("%d %d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	//	e[u].push_back(v);
	//	e[v].push_back(u);
	}
	dfn = 1;
	dfs(1, 0);
	memset(sum, 0, sizeof(int)*(2*n+1));
	for (int i = 1; i <= n; i++){
		a[i] = 1;
		add(l[i], 1);
		//add(r[i], -1);
	}
	scanf("%d", &m);
	int x;
	while(m--){
		scanf("%s %d", buf, &x);
		if (buf[0] == 'Q'){
			printf("%d\n", query(r[x]-1) - query(l[x]-1));
		}
		else{
			if (a[x]){
				add(l[x], -a[x]);
		//		add(r[x], a[x]);
				a[x] = 0;
			}
			else{
				add(l[x], 1);
		//		add(l[x], -1);
				a[x] = 1;
			}
		}
	}
	return 0;
}

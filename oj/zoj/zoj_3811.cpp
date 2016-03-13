#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct edge{
	int n, v;
} e[500000];
int T, n, m, k, l, esize, x, y;
int en[100100], f[100100], q[100100];
bool s[100100];
void addedge(int x, int y)
{
	e[esize].v = y;
	e[esize].n = en[x];
	en[x] = esize++;
}
int getf(int x){ return f[x]==x? x: f[x]=getf(f[x]);}
void unionxy(int x, int y){
	int xroot = getf(x),
	    yroot = getf(y);
	f[xroot] = yroot;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i <= n; i++) f[i] = i;
		memset(s, 0, sizeof(s));
		for (int i = 0; i < k; i++){
			scanf("%d", &x);
			s[x] = true;
		}
		esize = 0;
		memset(en, -1, sizeof(en));
		for (int i = 0; i < m; i++){
			scanf("%d %d", &x, &y);
			if ((!s[x]) && (!s[y])) unionxy(x, y);
			else{
				if (s[x]) addedge(x, y);
				if (s[y]) addedge(y, x);
			}
		}
		scanf("%d", &l);
		for (int i = 0; i < l; i++) scanf("%d", q+i);
		if (l != k){
			puts("No");
			continue;
		}
		bool legal = true;
		int first = q[0];
		for (int i = 0; i < l; i++){
			int u = q[i]; s[u] = 0;
			for (int t = en[u]; t != -1; t = e[t].n){
				int v = e[t].v;
				if (!s[v]) unionxy(u, v);
			}
			if (getf(u) != getf(first)){
				legal = false;
				break;
			}
		}
		if (legal){
			int father = getf(1), tmp;
			for (int i = 2; i <= n; i++){
				tmp = getf(i);
				if (tmp != father){
					legal = false;
					break;
				}
			}
		}
		if (legal) puts("Yes");
		else puts("No");
	}
	return 0;
}

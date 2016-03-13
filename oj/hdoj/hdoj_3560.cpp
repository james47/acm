#include<cstdio>
#include<cstring>
using namespace std;

int n, m, u, v;
bool flag[100100];
int f[100100], du[100100];
int getf(int x){ return f[x]==x?x:f[x]=getf(f[x]);}
void unionxy(int x, int y)
{
	int xroot = getf(x),
	    yroot = getf(y);
	f[xroot] = yroot;
}
int main()
{
	while(scanf("%d %d", &n, &m))
	{
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; i++) f[i] = i, du[i] = 0, flag[i] = true;
		for (int i = 0; i < m; i++){
			scanf("%d %d", &u, &v);
			du[u] ++, du[v] ++;
			unionxy(u, v);
		}
		int cc = 0, chain = 0;
		for (int i = 0; i < n; i++) if (du[i] != 2) flag[getf(i)] = false;
		for (int i = 0; i < n; i++) if (i == f[i]){
			cc++;
			if (flag[i]) chain ++;
		}
		printf("%d %d\n", cc, chain);
	}
	return 0;
}

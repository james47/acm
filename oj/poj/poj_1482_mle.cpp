#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxq = (1 << 20) + 10;
struct edge{
	int v, w, n;
} e[(1 << 20) + (1 << 19)];
int q[(1 << 20) + 100];
int n, m, maxn, oo, len, w, esize;
int f[(1 << 20) + 100];
int en[(1 << 20) + 100];
int cas = 0;
char s1[30], s2[30];
bool in[(1 << 20) + 100];
void addedge(int x, int y, int w)
{
	if (x == y) return;
	e[esize].v = y;
	e[esize].n = en[x];
	e[esize].w = w;
	en[x] = esize ++;
}
void dfs(int dep, int x, int y)
{
	if (dep == len){
		addedge(x, y, w);
		return;
	}
	if (s1[dep] == '0'){
		if (s2[dep] == '0') dfs(dep+1, x + (1 << dep), y + (1 << dep));
		else dfs(dep+1, x + (1 << dep), y);
	}
	dfs(dep+1, x, y);
}
void init()
{
	memset(f, 127, sizeof(f));
	oo = f[0];
	maxn = (1 << n) - 1;
	f[maxn] = 0;
	esize = 0;
	memset(en, -1, sizeof(en));
	for (int i = 0; i < m; i++){
		scanf("%d %s %s", &w, s1, s2);
		len = strlen(s1);
		int x = 0, y = 0;
		for (int j = 0; j < len; j++){
			if (s1[j] == '+') x += 1 << j;
			if (s2[j] == '+') y += 1 << j;
		}
		dfs(0, x, y);
	}
}
void spfa()
{
	int head, tail;
	head = tail = 0;
	q[tail++] = maxn;
	memset(in, false, sizeof(in));
	in[maxn] = true;
	while (head != tail)
	{
		int u = q[head++];
		if (head == maxq) head -= maxq;
		for (int t = en[u]; t != -1; t = e[t].n){
			int v = e[t].v;
			if (f[v] > f[u] + e[t].w){
				f[v] = f[u] + e[t].w;
				if (!in[v]){
					q[tail++] = v;
					if (tail == maxq) tail -= maxq;
					in[v] = true;
				}
			}
		}
		in[u] = false;
	}
}
void print()
{
	printf("Product %d\n", ++cas); 
	if (f[0] == oo) printf("Bugs cannot be fixed.\n");
	else printf("Fastest sequence takes %d seconds.\n", f[0]);
}
int main()
{
	while(scanf("%d %d", &n, &m) && n+m)
	{
		init();
		spfa();
		print();
	}
	return 0;
}

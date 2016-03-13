#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct edge{
	int u, v, w;
} e[20000];
int f[200];
int n, m, x;
bool cmp(edge a, edge b){
	return a.w < b.w;
}
int getf(int x){
	if (f[x] == x) return x;
	else return f[x] = getf(f[x]);
}
void unionxy(int x, int y){
	int xroot = getf(x), yroot = getf(y);
	f[xroot] = yroot;
}
int main()
{
	while(scanf("%d", &n) && n){
		m = n * (n-1) / 2;
		for (int i = 0; i < m; i++){
			scanf("%d %d %d %d", &e[i].u, &e[i].v, &e[i].w, &x);
			if (x) e[i].w = 0;
		}
		sort(e, e+m, cmp);
		for (int i = 1; i <= n; i++) f[i] = i;
		int sum = 0;
		for (int i = 0; i < m; i++)
			if (getf(e[i].u) != getf(e[i].v)){
				unionxy(e[i].u, e[i].v);
				sum += e[i].w;
			}
		printf("%d\n", sum);
	}
	return 0;
}

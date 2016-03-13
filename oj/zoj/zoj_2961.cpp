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

struct edge{
	char s[10];
	int w;
} e[300];
struct queue{
	int u, p, s, e;
} q[1003000];
int wei, cas, d, n, pos, st, ed;
int vis[1003000];
void output(int pos)
{
	if (q[pos].p == -1) return;
	output(q[pos].p);
	printf("%s\n", e[q[pos].e].s);
}
int trans(int u, int x)
{
	int ret = 0, v = e[x].w;
	int tt[10];
	for (int i = d-1; i >= 0; i--){
		tt[i] = (u + v) % 10;
		u /= 10, v /= 10;
	}
	for (int i = 0; i < d; i++)
		ret = ret * 10 + tt[i];
	return ret;
}
int bfs(int st, int ed)
{
	if (st == ed){
		return 0;
	}
	int head, tail;
	head = tail = 0;
	vis[st] = cas;
	q[tail].u = st;
	q[tail].p = -1;
	q[tail++].s = 0;
	while(head < tail)
	{
		int u = q[head].u;
		for (int i = 0; i < n; i++){
			int v = trans(u, i);
			if (vis[v] == cas) continue;
			vis[v] = cas;
			q[tail].e = i;
			q[tail].u = v;
			q[tail].s = q[head].s + 1;
			q[tail++].p = head;
			if (v == ed){
				pos = tail - 1;
				return q[head].s + 1;
			}

		}
		head ++;
	}
	return -1;
}
void init(int x)
{
	int tt[10];
	int tmp = e[x].w;
	for (int i = d-1; i >= 0; i--){
		tt[i] = tmp % 10;
		tmp /= 10;
	}
	for (int i = 0; i < d; i++){
		e[x].s[i] = tt[i] + '0';
	}
	e[x].s[d] = '\0';
}
bool cmp(edge a, edge b)
{
	return strcmp(a.s, b.s) < 0;
}
int main()
{
	cas = 0;
	memset(vis, 0, sizeof(vis));
	while(scanf("%d %d", &d, &n) != EOF)
	{
		cas ++;
		for (int i = 0; i < n; i++){
			scanf("%d", &e[i].w);
			init(i);
		}
		sort(e, e+n, cmp);
//		for (int i = 0; i < n; i++)
//			printf("%s\n", e[i].s);
		scanf("%d %d", &st, &ed);
		int ans = bfs(st, ed);
		printf("%d\n", ans);
		if (ans != -1 && ans != 0) output(pos);
	}
	return 0;
}

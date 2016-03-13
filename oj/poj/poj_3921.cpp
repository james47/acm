#include<cstdio>
#include<cstring>
using namespace std;

const int qsize = 799999;
struct queue{
	int cnt;
	bool del[52];
} q[800000];
struct qq{
	int u, w, pre;
} qu[60];
int n, m, k, hh, tt;
int ans;
bool findans;
bool v[55];
bool e[55][55];
void bfs(int x)
{
	memset(v, false, sizeof(v));
	for (int i = 1; i <= n; i++)
		if (q[x].del[i]) v[i] = true;
	int pos = 0;
	int h = 0, t = 0;
	v[1] = true;
	qu[t].pre = -1;
	qu[t].w = 0;
	qu[t++].u = 1;
	bool unreach = true;
	while(h < t)
	{
		int u = qu[h].u;
		if (u == n){
			unreach = false;
			pos = h;
			break;
		}
		for (int i = 1; i <= n; i++)
			if (e[u][i] && !v[i]){
				v[i] = true;
				qu[t].pre = h;
				qu[t].w = qu[h].w + 1;
				qu[t++].u = i;
			}
		h++;
	}
	if (unreach || qu[pos].w > k){
		findans = true;
	//	printf("shortest %d\n", qu[pos].w);
		return;
	}
	while(qu[pos].pre != -1){
		int u = qu[pos].u;
		//printf("%d %d\n", x, u);
		if (u != 1 && u != n)
			if (!q[x].del[u]){
				for (int i = 1; i <= n; i++)
					q[tt].del[i] = q[x].del[i];
				q[tt].del[u] = true;
				q[tt].cnt = q[x].cnt + 1;
				tt++;
				if (tt >= qsize) tt -= qsize;
			}
		pos = qu[pos].pre;
	}
}
int main()
{
	while(scanf("%d%d%d", &n, &m, &k) && (n+m+k))
	{
		memset(e, false, sizeof(e));
		int x, y;
		for (int i = 0; i < m; i++){
			scanf("%d %d", &x, &y);
			e[x][y] = true;
		}
		hh = 0, tt = 0;
		memset(q[0].del, false, sizeof(q[0].del));
		q[tt++].cnt = 0;
		findans = false;
		ans = n-2;
		while(hh != tt)
		{
			//printf("hh %d\n", hh);
			bfs(hh);
			if (findans){
				//printf("%d  %d\n", hh, q[hh].cnt);
				ans = q[hh].cnt;
				break;
			}
			hh++;
			if (hh >= qsize) hh -= qsize;
		}
		/*
		for (int i = 0; i < tt; i++){
			printf("index is %d \n cnt is %d\n", i, q[i].cnt);
			for (int j = 1; j <= n; j++)
				printf("%d ", q[i].del[j]);
			printf("\n");
		}
		*/
		printf("%d\n", ans);
	}
	return 0;
}

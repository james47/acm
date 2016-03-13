#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct edge{
	int n, v;
} e[3][603000];
int ans[3000][3], en[3][3000], in[3][3000];
int n, r, esize[3];
void insert(int t, int u, int v)
{
	e[t][esize[t]].v = v;
	e[t][esize[t]].n = en[t][u];
	en[t][u] = esize[t];
	esize[t] ++;
	in[t][v]++;
}
int main()
{
	int x, y, ca = 0;
	char ch[10];
	while(scanf("%d %d", &n, &r) && (n + r))
	{
		ca ++;
		memset(in, 0, sizeof(in));
		memset(en, -1, sizeof(en));
		memset(esize, 0, sizeof(esize));
		for (int i = 1; i <= n; i++){
			insert(0, i, i+n);
			insert(1, i, i+n);
			insert(2, i, i+n);
		}
		for (int i = 0; i < r; i++){
			//getchar();
			scanf("%s %d %d", ch, &x, &y);
			if (ch[0] == 'I'){
				insert(0, x, y+n);
				insert(1, x, y+n);
				insert(2, x, y+n);
				insert(0, y, x+n);
				insert(1, y, x+n);
				insert(2, y, x+n);
			}
			else if (ch[0] == 'X'){
				insert(0, x+n, y);
			}
			else if (ch[0] == 'Y'){
				insert(1, x+n, y);
			}
			else if (ch[0] == 'Z')
				insert(2, x+n, y);
		}
		bool findans = true;
		for (int t = 0; t < 3; t++){
			queue<int> q;
			for (int i = 1; i <= n * 2; i++){
				if (in[t][i] == 0) {//printf("t:%d %d\n", t, i);
					q.push(i);
				}
			}
			int u, v, p;
			int cnt = 0;
			while(!q.empty()){
				int u = q.front(); q.pop();
				ans[u][t] = ++cnt;
				for (p = en[t][u]; p != -1; p = e[t][p].n){
					v = e[t][p].v;
					in[t][v] --;
					if (!in[t][v]){//printf("t:%d %d\n", t, v);
						q.push(v);
					}
				}
			}
			//printf("%d\n", cnt);
			if (cnt != (n*2)) {findans = false; break;}
		}
		if (findans){
			printf("Case %d: POSSIBLE\n", ca);
			for (int i = 1; i <= n; i++)
				printf("%d %d %d %d %d %d\n", ans[i][0], ans[i][1], ans[i][2], 
							      ans[i+n][0], ans[i+n][1], ans[i+n][2]);
		}
		else
			printf("Case %d: IMPOSSIBLE\n", ca);
		if (ca >= 1) printf("\n");
	}
	return 0;
}

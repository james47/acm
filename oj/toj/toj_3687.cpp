#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;

int ans[210], in[210];
bool e[210][210];
int main()
{
	int T, n, m, x, y;
	scanf("%d", &T);
	while(T--)
	{
		memset(e, false, sizeof(e));
		memset(in, 0, sizeof(in));
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++){
			scanf("%d %d", &x, &y);
			if (!e[y][x]){
				e[y][x] = true;
				in[x] ++;
			}
		}
		priority_queue<int> q;
		for (int i = 1; i <= n; i++)
			if (!in[i]) q.push(i);
		int cnt = n;
		while(!q.empty()){
			int u = q.top(); q.pop();
			ans[u] = cnt --;
			for (int i = 1; i <= n; i++)
				if (e[u][i]){
					in[i] --;
					if (!in[i]) q.push(i);
				}
		}
		if (cnt == 0){
			for (int i = 1; i < n; i++)
				printf("%d ", ans[i]);
			printf("%d\n", ans[n]);
		}
		else printf("-1\n");
	}
	return 0;
}

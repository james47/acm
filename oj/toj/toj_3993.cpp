#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int ans[110], in[110];
bool e[110][110];
int n, m;
int main()
{
	int T, x, y;
	scanf("%d", &T);
	while(T--)
	{
		memset(e, 0, sizeof(e));
		memset(in, 0, sizeof(in));
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++){
			scanf("%d %d", &x, &y);
			if (!e[x][y]){
				e[x][y] = 1;
				in[y]++;
			}
		}
		priority_queue<int, vector<int>, greater<int> > q;
		for (int i = 1; i <= n; i++)
			if (!in[i]) q.push(i);
		int cnt = 0;
		while(!q.empty()){
			int u = q.top();
			q.pop();
			ans[++cnt] = u;
			for (int i = 1; i <= n; i++)
				if (e[u][i]){
					in[i]--;
					if (!in[i]) q.push(i);
				}
		}
		if (cnt == n){
			for (int i = 1; i <= n; i++)
				printf("%d ", ans[i]);
			printf("\n");
		}
		else printf("Low IQ\n");
	}
	return 0;
}

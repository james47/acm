#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;

int en[510], in[510];
int n, m, x, y, esize;
struct edge{
	int n, v;
} e[30000];
void insert(int u, int v)
{
	esize ++;
	e[esize].v = v;
	e[esize].n = en[u];
	en[u] = esize;
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		memset(en, -1, sizeof(en));
		memset(in, 0, sizeof(in));
		esize = -1;
		for(int i = 0; i < m; i++){
			scanf("%d %d", &x, &y);
			insert(x, y);
			in[y]++;
		}
		priority_queue<int, vector<int>, greater<int> > q;
		for (int i = 1; i <= n; i++){
			if (!in[i]) q.push(i);
		}
		bool flag = true;
		while(!q.empty()){
			int t = q.top(); q.pop();
			if (flag){
				flag = false;
				printf("%d", t);
			}
			else printf(" %d", t);
			for (int tt = en[t]; tt != -1; tt = e[tt].n){
				int v = e[tt].v;
				in[v]--;
				if (!in[v]) q.push(v);
			}
		}
		printf("\n");
	}
	return 0;
}

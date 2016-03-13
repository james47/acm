#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 55;
int n, m, edge[maxn][maxn], dist[maxn];
bool inset[maxn];

void init(){ 
	scanf("%d", &m);
	memset(edge, 127, sizeof(edge));
	int x, y, z;
	for (int i = 0; i < m; i++){
		scanf("%d %d %d", &x, &y, &z);
		edge[x][y] = edge[y][x] = min(edge[x][y], z);
	}
}
int prim(){
	memset(dist, 127, sizeof(dist));
	memset(inset, false, sizeof(inset));
	dist[1] = 0; int ret = 0;
	for (int i = 0; i < n; i++){
		int v = 0;
		for (int j = 1; j <= n; j++)			//O(n)查找拥有最小dist且不在S中的节点v
			if (!inset[j] && (v == 0 || dist[j] < dist[v])) v = j;
		ret += dist[v]; inset[v] = true;		//将v加入集合S，即inset[v] = true;
		for (int j = 1; j <= n; j++) 			//用新加入S的v节点来更新其他点的dist值
			if (!inset[j] && dist[j] > edge[v][j]) dist[j] = edge[v][j];
	}
	return ret;
}

int main()
{
	while(scanf("%d", &n) && n){
		init();
		printf("%d\n", prim());
	}
	return 0;
}

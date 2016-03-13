#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 55;
int n, m, f[maxn];

struct edge{
	int u, v, w;
} e[30000];

void init(){ //union-find sets initialize
	for (int i = 0; i <= n; i++) f[i] = i;
} 
int find(int x){ 			//返回x所在集合代表元素，即根节点
	if (f[x] == x) return x;	//为root
	else return f[x] = find(f[x]);  // "f[x] =" 即完成了路径压缩优化，递归结束后f[x]为x所在集合根节点
} 
void merge(int x, int y){		//合并x和y所在集合
	f[find(x)] = find(y);		//将x所在集合的根节点合并到y所在集合根节点下
}

bool cmp(edge a, edge b){ return  a.w < b.w; }	//为sort定义比较函数
int kruskal(){
	int ret = 0;
	init();
	sort(e, e+m, cmp);	//将边按权值递增排列
	for (int i = 0; i < m; i++){
		if (find(e[i].u) != find(e[i].v)){	//不属于一棵树，合并，否则continue
			merge(e[i].u, e[i].v);
			ret += e[i].w;
		}
	}
	return ret;
}
int main()
{
	while(scanf("%d", &n) && n){
		scanf("%d", &m);
		for (int i = 0; i < m; i++) scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
		printf("%d\n", kruskal());
	}
	return 0;
}

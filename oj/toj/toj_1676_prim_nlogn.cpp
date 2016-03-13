/*
以下为用STL优先队列实现的Prim算法，由于没有提供修改堆中元素键值并调整位置的函数，所以我们的对策是将更小的值直接push入队列，
带来的坏处即是堆所耗费的空间由O(V)变为O(E)，且实际运行时间会比自己写的堆更慢，但是从复杂度分析来看时间也还是O(Elog(V))的
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 55;
int n, m, dist[maxn];
bool inset[maxn];
vector<pair<int, int> > e[maxn];	//为每个节点声明一个vector，pair是一对数，存放对应点和权值

void init(){ 
	scanf("%d", &m);
	for (int i = 1; i <= n; i++) e[i].clear();	//多组数据，每次清空vector中的边
	int x, y, z;
	for (int i = 0; i < m; i++){
		scanf("%d %d %d", &x, &y, &z);
		e[x].push_back(make_pair(y, z));	//将边push入vector
		e[y].push_back(make_pair(x, z));
	}
}
int prim(){
	memset(dist, 127, sizeof(dist));
	memset(inset, false, sizeof(inset));
	int ret = 0, cnt = 0; dist[1] = 0;
	priority_queue<pair<int, int> > q;		//声明优先队列，默认队首为最大值
	q.push(make_pair(0, 1));			//pair的第一键值优先级高于第二键值，所以我们把边权放在前面,和上面的e[][]相反
	while(cnt < n){					//cnt记录S中的顶点个数
		pair<int, int> tmp = q.top(); q.pop();	//取出队首并pop弹出
		int v = tmp.second, w = -tmp.first;i	//我们需要最小值，所以放入队列时权值取负数，取出也要取反
		if (inset[v]) continue;			//如果v已经在S中则跳过
		cnt++; ret += w; inset[v] = true;	//否则加入S
		for (int j = 0; j < e[v].size(); j++){	//用v来更新相连点的dist[]值
			int u = e[v][j].first, w = e[v][j].second;
			if (!inset[u] && dist[u] > w){
				dist[u] = w;
				q.push(make_pair(-w, u));	//注意是将负的权值加入优先队列
			}
		}
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

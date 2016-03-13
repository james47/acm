#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
#include<cstring>
#include<string>
using namespace std;

//char x[50], y[50];
typedef pair<int, int> P;
string x, y;
int n, esize;
struct edge{
    int v, n, w;
} e[30000];
int d[1000], en[1000];
bool vis[1000];
void insert(int u, int v, int w){
    e[esize].v = v;
    e[esize].w = w;
    e[esize].n = en[u];
    en[u] = esize++;
}
int dijkstra(int st, int ed)
{
    memset(d, -1, sizeof(d));
    memset(vis, false, sizeof(vis));
    d[st] = 0;
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(make_pair(d[st], st));
    while(!q.empty()){
        P pp = q.top(); q.pop();
        int u = pp.second;
        //if (u == ed) return d[u];
        if (vis[u]) continue;
        vis[u] = true;
        for (int t = en[u]; t != -1; t = e[t].n){
            int v = e[t].v;
            if (d[v] == -1 || d[v] > d[u] + e[t].w){
                d[v] = d[u] + e[t].w;
                q.push(make_pair(d[v], v));
            }
        }
    }
    return d[ed];
}
int main()
{
    while(scanf("%d", &n) && n != -1)
    {
        int w, cnt = 1;
        map<string, int> h;
        h.clear();
        cin >> x >> y;
        h[x] = cnt ++;
        if (h[y] == 0) h[y] = cnt ++;
        int st = h[x], ed = h[y];
        memset(en, -1, sizeof(en));
        esize = 0;
        for (int i = 0; i < n; i++){
            cin >> x >> y >> w;
            if (h[x] == 0) h[x] = cnt ++;
            if (h[y] == 0) h[y] = cnt ++;
            insert(h[x], h[y], w);
            insert(h[y], h[x], w);
        }
        printf("%d\n", dijkstra(st, ed));
    }
    return 0;
}

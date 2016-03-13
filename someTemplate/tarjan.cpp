//强连通分量缩点

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int en[10010], col[10010], dfn[10010], low[10010], stack[10010], tot[10010], chu[10010];
bool ins[10010];
int n, m, esize, dtime, stop, scc;
struct edge{
    int v, n;
} e[50010];
void insert(int u, int v)
{
    e[esize].v = v;
    e[esize].n = en[u];
    en[u] = esize ++;
}
void dfs(int x)
{
    dfn[x] = low[x] = dtime ++;
    stack[stop++] = x;
    ins[x] = true;
    for (int t = en[x]; t != -1; t = e[t].n){
        int v = e[t].v;
        if (!dfn[v]){
            dfs(v);
            low[x] = min(low[x], low[v]);
        }
        else if (ins[v]){
            low[x] = min(low[x], dfn[v]);
        }
    }
    if (dfn[x] == low[x]){
        scc ++;
        while(stack[--stop] != x){
            col[stack[stop]] = scc;
            ins[stack[stop]] = false;
        }
        col[x] = scc;
        ins[x] = false;
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    int a, b;
    esize = 0;
    memset(en, -1, sizeof(en));
    for (int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        insert(a, b);
    }
    memset(dfn, 0, sizeof(dfn));
    memset(col, 0, sizeof(col));
    memset(ins, 0, sizeof(ins));
    dtime = 1; stop = 0; scc = 0;
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) dfs(i);
    memset(chu, 0, sizeof(chu));
    memset(tot, 0, sizeof(tot));
    for (int i = 1; i <= n; i++){
        int u = col[i];
        tot[u]++;
        for (int t = en[i]; t != -1; t = e[t].n){
            int v = col[e[t].v];
            if (u != v)
                chu[u] ++;
        }
    }
    int cnt = 0, ans;
    for (int i = 1; i <= scc; i++)
        if (chu[i] == 0){
            cnt ++;
            ans = tot[i];
        }
    if (cnt > 1) ans = 0;
    printf("%d\n", ans);
    return 0;
} 


//求割点数量
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int esize, n, root, dtime;
struct edge{
    int v, n;
} e[100000];
int en[200], dfn[200], low[200];
bool cut[200];
int min(int a, int b)
{
    if (a < b) return a; else return b;
}
void insert(int u, int v)
{
    e[esize].v = v;
    e[esize].n = en[u];
    en[u] = esize++;
}
void dfs(int x, int fa)
{
    int son = 0;
    dfn[x] = low[x] = dtime++;
    for (int t = en[x]; t != -1; t = e[t].n){
        int v = e[t].v;
        if (v == fa) continue;
        if (!dfn[v]){
            son++;
            dfs(v, x);
            low[x] = min(low[x], low[v]);
            if ((x != root && low[v] >= dfn[x]) || (x == root && son > 1))
                cut[x] = true;
        }
        else{
            low[x] = min(low[x], dfn[v]);
        }
    }
}
int main()
{
    while(scanf("%d", &n) == 1 && n)
    {
        memset(en, -1, sizeof(en));
        int x, y, esize = 0;
        char ch;
        while(scanf("%d", &x) == 1 && x){
            while((ch = getchar()) != '\n'){
                scanf("%d", &y);
                insert(x, y);
                insert(y, x);
            }
        }
        memset(dfn, 0, sizeof(dfn));
        memset(cut, 0, sizeof(cut));
        root = 1; dtime = 1;
        dfs(1, 0);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (cut[i]) {
                ans++;
            }
        printf("%d\n", ans);
    }
    return 0;
}

//无向图求桥
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int inf = 2147483647;
int esize, n, m, dtime, ans;
int low[1010], dfn[1010], en[1010], f[1010];
struct edge{
    int v, n, w;
    bool u;
} e[2002000];
int getf(int x)
{
    if (x == f[x]) return x;
    f[x] = getf(f[x]);
    return f[x];
}
void unionxy(int x, int y)
{
    int xroot = getf(x),
        yroot = getf(y);
    f[xroot] = yroot;
}
void insert(int u, int v, int w){
    e[esize].v = v;
    e[esize].n = en[u];
    e[esize].w = w;
    e[esize].u = false;
    en[u] = esize ++;
}
void dfs(int u)
{
    low[u] = dfn[u] = dtime ++;
    for (int t = en[u]; t != -1; t = e[t].n){
        if (e[t^1].u) continue;
        e[t].u = true;
        int v = e[t].v;
        if (!dfn[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]){
                if (e[t].w == 0)
                    ans = min(ans, 1);
                else
                    ans = min(ans, e[t].w);
            }
        }
        else
            low[u] = min(low[u], dfn[v]);
    }
}
int main()
{
    while(scanf("%d %d", &n, &m) && (n + m))
    {
        memset(en, -1, sizeof(en));
        esize = 0;
        for (int i = 1; i <= n; i++)
            f[i] = i;
        int x, y, w;
        for (int i = 0; i < m; i++){
            scanf("%d %d %d", &x, &y, &w);
            insert(x, y, w);
            insert(y, x, w);
            unionxy(x, y);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (f[i] == i) cnt ++;
        if (cnt > 1){
            puts("0");
            continue;
        }
        memset(dfn, 0, sizeof(dfn));
        dtime = 1, ans = inf;
        for (int i = 1; i <= n; i++)
            if (!dfn[i]) dfs(i);
        if (ans == inf) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}  

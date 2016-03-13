#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n, root;
int f[1000], lv[1000], p[1000][12], ans[1000];
vector<int> son[900];
int in()
{
    int ret = 0;
    char ch = getchar();
    while(!(ch >= '0' && ch <= '9')) ch = getchar();
    while(ch >= '0' && ch <= '9'){
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    return ret;
}
void dfs(int x, int dep)
{
    lv[x] = dep;
    for (int i = 0; i < son[x].size(); i ++)
        dfs(son[x][i], dep+1);
}
void work()
{
    memset(p, 0, sizeof(p));
    for (int i = 0; i <= n; i++)
        p[i][0] = f[i];
    for (int j = 1; (1 << j) <= n; j++){
        for (int i = 1; i <= n; i++){
            int tmp = p[i][j-1];
            p[i][j] = p[tmp][j-1];
        }
    }
}
int lca(int x, int y)
{
    if (lv[x] < lv[y]) swap(x, y);
    int log;
    for (log = 1; (1 << log) <= lv[x]; log++);
    log --;
    for (int i = log; i >= 0; i--){
        //if (lv[x] - (1 << i) >= lv[y]) x = p[x][i];
        int tmp = p[x][i];
        if (tmp != 0 && lv[tmp] >= lv[y]) x = p[x][i];
    }
    if (x == y) return x;
    for (int i = log; i >= 0; i--){
        if (p[x][i] != p[y][i] && p[x][i] != 0) x = p[x][i], y = p[y][i];
    }
    return f[x];
}
int main()
{
    while(scanf("%d", &n) != EOF)
    {
        memset(f, 0, sizeof(f));
        int x, y, z;
        for (int i = 0; i < n; i++){
            x = in(); y = in();
            son[x].clear();
            for (int j = 1; j <= y; j++){
                z = in();
                f[z] = x;
                son[x].push_back(z);
            }
        }
        for (int i = 1; i <= n; i++)
            if (f[i] == 0) root = i, f[root] = root;
        dfs(root, 1);
        work();
        int q;
        q = in();
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < q; i++){
            x = in(); y = in();
            ans[lca(x, y)] ++;
        }
        for (int i = 1; i <= n; i++) if (ans[i])
            printf("%d:%d\n", i, ans[i]);
    }
    return 0;
}


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int, int> P;
const int maxn = 40100;

int T, n, m, x, y, z;
int f[maxn], d[maxn], ans[300];
bool vis[maxn];
vector<P> e[maxn], q[maxn];

int getf(int x)
{
    if (f[x] == x) return x;
    return f[x] = getf(f[x]);
}
void unionxy(int x, int y)
{
    int xroot = getf(x), yroot = getf(y);
    f[yroot] = xroot;
}
void tarjan(int x)
{
    f[x] = x;
    vis[x] = true;
    for (int i = 0; i < q[x].size(); i++){
        int v = q[x][i].first, id = q[x][i].second;
        if (vis[v]){
            int lca = f[getf(v)];
            ans[id] = d[x] + d[v] - 2 * d[lca];
        }
    }
    for (int i = 0; i < e[x].size(); i++){
        int v = e[x][i].first, w = e[x][i].second;
        if (!vis[v]){
            d[v] = d[x] + w;
            tarjan(v);
            unionxy(x, v);
            f[getf(x)] = x;
        }
    }
}
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i <= n; i++){
            q[i].clear(); e[i].clear();
        }
        for (int i = 1; i < n; i++){
            scanf("%d%d%d", &x, &y, &z);
            e[x].push_back(make_pair(y, z));
            e[y].push_back(make_pair(x, z));
        }
        for (int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            if (x == y) ans[i] = 0;
            else{
                q[x].push_back(make_pair(y, i));
                q[y].push_back(make_pair(x, i));
            }
        }
        memset(vis, 0, sizeof(vis));
        d[1] = 0;
        tarjan(1);
        for (int i = 0; i < m; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}  

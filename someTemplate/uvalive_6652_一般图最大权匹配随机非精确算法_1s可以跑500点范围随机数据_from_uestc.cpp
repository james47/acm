#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

const int MAXN = 110;
const int INF = 0x3f3f3f3f;

int G[MAXN][MAXN];
int cnt_node;//点的个数
int dis[MAXN];
int match[MAXN];
bool vis[MAXN];
int sta[MAXN], top;

bool dfs(int u)
{
    sta[top++] = u;
    if (vis[u])return true;
    vis[u] = true;
    for (int i = 0; i < cnt_node; i++)
        if (i != u && i != match[u] && !vis[i])
        {
            int t = match[i];
            if (dis[t] < dis[u] + G[u][i] - G[i][t])
            {
                dis[t] = dis[u] + G[u][i] - G[i][t];
                if (dfs(t))return true;
            }
        }
    top--;
    vis[u] = false;
    return false;
}

int P[MAXN];

int get_Match(int N)//返回最大匹配权值
{
    cnt_node = N;
    for (int i = 0; i < cnt_node; i++)P[i] = i;
    for (int i = 0; i < cnt_node; i += 2)
    {
        match[i] = i + 1;
        match[i + 1] = i;
    }
    int cnt = 0;
    while (1)
    {
        memset(dis, 0, sizeof(dis));
        memset(vis, false, sizeof(vis));
        top = 0;
        bool update = false;
        for (int i = 0; i < cnt_node; i++)
            if (dfs(P[i]))
            {
                update = true;
                int tmp = match[sta[top - 1]];
                int j = top - 2;
                while (sta[j] != sta[top - 1])
                {
                    match[tmp] = sta[j];
                    swap(tmp, match[sta[j]]);
                    j--;
                }
                match[tmp] = sta[j];
                match[sta[j]] = tmp;
                break;
            }
        if (!update)
        {
            cnt++;
            if (cnt >= 3)break;
            random_shuffle(P, P + cnt_node);
        }
    }
    int ans = 0;
    for (int i = 0; i < cnt_node; i++)
    {
        int v = match[i];
        if (i < v)ans += G[i][v];
    }
    return ans;
}

int g[MAXN][MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ca++)
    {
        printf("Case %d: ", ca);
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);

        memset(g, INF, sizeof(g));
        for (int i = 0; i < n; i++)
            g[i][i] = 0;

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            u--, v--;
            g[u][v] = g[v][u] = w;
        }

        if (k % 2 == 1)
        {
            puts("Impossible");
            continue;
        }

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                G[i][j] = -g[i][j];

        cout << -get_Match(k) << endl;
    }
    return 0;
}

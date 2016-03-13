#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<ctime>
#include<string>
using namespace std;

const int maxn = 10010;
int n, m, inf;
int next[maxn * 10 * 2];
int p[2][maxn * 10 * 2], a[maxn * 10], aa[maxn * 10], b[maxn][15], ct[maxn];
int get(int x)
{
    if (x == next[x]) return x;
    next[x] = get(next[x]);
    return next[x];
}
void insert(int x, int pos, int t)
{
    pos = get(pos);
    next[pos] = next[pos+1];
    p[t][pos] = x;
}
void init()
{
    scanf("%d %d", &n, &m);
    int x, pos;
    memset(p, 0, sizeof(p));
    for (int i = 0; i <= 2 * m * n; i++)
        next[i] = i;
    for (int i = 1; i <= m * n; i++){
        scanf("%d %d", &x, &pos);
        insert(x, pos, 0);
    }
    for (int i = 0; i <= 2 * m * n; i++)
        next[i] = i;
    for (int i = 1; i <= m * n; i++){
        scanf("%d %d", &x, &pos);
        insert(x, pos, 1);
    }
    memset(ct, 0, sizeof(ct));
    int pp = 0, ppp = 0;
    for (int i = 1; i <= 2 * m * n; i++){
        if (p[0][i]) a[pp++] = p[0][i];
        if (p[1][i]) aa[ppp++] = p[1][i];
    }
    for (int i = 0; i < n * m; i++){
        int x = a[i];
        b[x][ct[x]++] = i;
    }
    /*
    for (int i = 0; i < n * m; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < n * m; i++){
        printf("%d ", aa[i]);
    }
    printf("\n");
    */
}

int f[maxn * 10];

int find(int x)
{
    int l = 1, r = n * m, pos = inf;
    while(l <= r)
    {
        int mid = l + r >> 1;
        if (x <= f[mid]){
            pos = min(pos, mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return pos;
}
int dp()
{
    memset(f, 127, sizeof(f));
    inf = f[0];
    for (int i = 0; i < n * m; i++){
        int x = aa[i];
        for (int j = ct[x]-1; j >= 0; j--){
            int pos = find(b[x][j]);
            f[pos] = b[x][j];
            //printf("%d %d %d\n", x, pos, f[pos]);
        }
    }
    int ans = 0;
    for (int i = n * m; i >= 1; i--)
        if (f[i] != inf){
            ans = i;
            break;
        }
    return ans;
}
int main()
{
    int T, cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        init();
        cas++;
        printf("Case #%d: %d\n", cas, dp());
    }
    return 0;
}

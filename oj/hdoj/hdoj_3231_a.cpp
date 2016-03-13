#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct edge{
    int n, v;
} e[3][300000];
int ans[1100][3][2], en[3][3000], in[3][3000];
int n, r, esize[3];
void insert(int t, int u, int v)
{
    e[t][esize[t]].v = v;
    e[t][esize[t]].n = en[t][u];
    en[t][u] = esize[t];
    esize[t] ++;
    in[t][v]++;
}
int main()
{
    int x, y, ca = 0;
    char ch[10];
    while(scanf("%d %d", &n, &r) && (n + r))
    {
        ca ++;
        memset(in, 0, sizeof(in));
        memset(en, -1, sizeof(en));
        memset(esize, 0, sizeof(esize));
        for (int i = 1; i <= n; i++){
            insert(0, (i<<1)-1, i<<1);
            insert(1, (i<<1)-1, i<<1);
            insert(2, (i<<1)-1, i<<1);
        }
        for (int i = 0; i < r; i++){
            //getchar();
            scanf("%s %d %d", ch, &x, &y);
            if (ch[0] == 'I'){
                insert(0, (y<<1)-1, x<<1);
                insert(1, (y<<1)-1, x<<1);
                insert(2, (y<<1)-1, x<<1);
		insert(0, (x<<1)-1, y<<1);
		insert(1, (x<<1)-1, y<<1);
		insert(2, (x<<1)-1, y<<1);
            }
            else if (ch[0] == 'X'){
                insert(0, x<<1, (y<<1)-1);
            }
            else if (ch[0] == 'Y'){
                insert(1, x<<1, (y<<1)-1);
            }
            else if (ch[0] == 'Z')
                insert(2, x<<1, (y<<1)-1);
        }
        bool findans = true;
        for (int t = 0; t < 3; t++){
            queue<int> q;
            for (int i = 1; i <= n << 1; i++){
                if (in[t][i] == 0) {//printf("t:%d %d\n", t, i);
                    q.push(i);
                }
            }
            int u, v, p;
            int cnt = 0;
            while(!q.empty()){
                int u = q.front(); q.pop();
                ans[(u+1)>>1][t][(u&1)^1] = cnt++;
                for (p = en[t][u]; p != -1; p = e[t][p].n){
                    v = e[t][p].v;
                    in[t][v] --;
                    if (!in[t][v]){//printf("t:%d %d\n", t, v);
                        q.push(v);
                    }
                }
            }
            if (cnt != (n << 1)) {findans = false; break;}
        }
        if (findans){
            printf("Case %d: POSSIBLE\n", ca);
            for (int i = 1; i <= n; i++)
                printf("%d %d %d %d %d %d\n", ans[i][0][0], ans[i][1][0], ans[i][2][0], 
                                  ans[i][0][1], ans[i][1][1], ans[i][2][1]);
        }
        else
            printf("Case %d: IMPOSSIBLE\n", ca);
        if (ca >= 1) printf("\n");
    }
    return 0;
}

/*************************************************************************
    > File Name: poj_1185.cpp
    > Author: james47
    > Mail: 
    > Created Time: Mon Aug  3 16:13:49 2015
 ************************************************************************/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m, cnt, size;
int a[110], st[70], ct[70];
char str[15];
int f[110][70][70];
void init()
{
    size = 0;
    int maxn = 1 << m;
    for (int i = 0; i < maxn; i++){
        if (!(i&(i<<2)) && !(i&(i<<1))){
            st[size] = i;
            ct[size] = 0;
            int tmp = i;
            while(tmp) tmp = tmp&(tmp-1), ct[size]++;
            size++;
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%s", str);
        a[i] = 0;
        for (int j = 0; j < m; j++){
            if (str[j] == 'H') a[i] |= 1 << j;
        }
    }
    init();
    memset(f, 0, sizeof(f));
    for (int j = 0; j < size; j++){
        if (!(a[1]&st[j])) f[1][j][0] = ct[j];
    }
    for (int i = 2; i <= n; i++){
        for (int j = 0; j < size; j++){
            if (a[i]&st[j]) continue;
            for (int k = 0; k < size; k++){
                if (a[i-1]&st[k]) continue;
                if (i == 2){
                    if (!(st[j]&st[k]))
                        f[i][j][k] = max(f[i][j][k], f[i-1][k][0] + ct[j]);
                }
                else for (int l = 0; l < size; l++){
                    if (!(a[i-2]&st[l]) && !(st[j]&st[k]) && !(st[j]&st[l]) && !(st[k]&st[l]))
                        f[i][j][k] = max(f[i][j][k], f[i-1][k][l] + ct[j]);
                }
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < size; j++)
        for (int k = 0; k < size; k++)
            ans = max(ans, f[n][j][k]);
    printf("%d\n", ans);
    return 0;
}

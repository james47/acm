/*
*二维RMQ ST算法
*构造RMQ数组 makermq(int n,int m,int b[][]) O(n*m*log(n)*log(m))算法复杂度
*st[i][j][row][col] 表示 行从row ->row +2^i-1 列从col ->col +2^j-1 二维区间里最大值
*st[row][col][i][j] = 下行
*max{st[i][j-1][row][col],st[i-1][j][row][col],st[i][j-1][row][col+2^(j-1)],st[col][i-1][j][row+2^(i-1)]}
*查询RMQ rmq(int sx,int ex,int sy,int ey)
*同一维的将sx->ex 分为两个2^kx区间 将 sy->ey分为两个2^ky的区间
*kx=(int)log2(ex-sx+1) ky=(int)log2(ey-sy+1)
*log2()可能会CE
*查询结果为
*max{st[kx][ky][sx][sy],st[kx][ky][sx][ey-2^ky+1],
*st[kx][ky][ex-2^kx+1][sy],st[kx][ky][ex-2^kx+1][ey-2^ky+1]}
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
const int N = 310;
const int M = 10;
int map[N][N];
int st[M][M][N][N];
ll A[N][N],B[N][N];
int POW[] = { 1, 1 << 1, 1 << 2, 1 << 3, 1 << 4, 1 << 5, 1 << 6, 1 << 7,
        1 << 8, 1 << 9, 1 << 10 };
void makermq(int n, int m, int b[][N]) {
    int row, col, i, j;
    for (row = 1; row <= n; row++) {
        for (col = 1; col <= m; col++) {
            st[0][0][row][col] = b[row][col];
        }
    }
    for (i = 0; POW[i] <= n; i++) {
        for (j = 0; POW[j] <= m; j++) {
            if (i == 0 && j == 0)
                continue;
            for (row = 1; row + POW[i] - 1 <= n; row++) {
                for (col = 1; col + POW[j] - 1 <= m; col++) {
                    if (i == 0) {
                        st[i][j][row][col] = max(st[i][j - 1][row][col],
                                st[i][j - 1][row][col + POW[j - 1]]);
                    } else {
                        st[i][j][row][col] = max(st[i - 1][j][row][col], st[i
                                - 1][j][row + POW[i - 1]][col]);
                    }
                }
            }
        }
    }
}

inline int get_k(int a, int b) {
    return (int) (log((b - a + 1) * 1.0)/log(2.0));
}

inline int RMQ(int x1, int x2, int y1, int y2) {

    int kx = get_k(x1, x2), ky = get_k(y1, y2);
    int max1, max2;// min1, min2;
    max1 = max(st[kx][ky][x1][y1], st[kx][ky][x1][y2 - POW[ky] + 1]);
    max2 = max(st[kx][ky][x2 - POW[kx] + 1][y1],
            st[kx][ky][x2 - POW[kx] + 1][y2 - POW[ky] + 1]);
    return max(max1, max2) ;//- min(min1, min2);
}

double cal(int x1, int y1, int x2, int y2 ,int n) {
    ll re = (long long)RMQ(x1, x2, y1, y2);
    ll aa = (long long)A[x2][y2]+A[x1-1][y1-1]-A[x2][y1-1]-A[x1-1][y2];
    ll bb = (long long)B[x2][y2]+B[x1-1][y1-1]-B[x2][y1-1]-B[x1-1][y2];
    aa-=re, bb-=re*re;
    double ans = 1.0*(bb-1.0*aa*aa/n)/n;
    return ans;
}

int main(){
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int q,i,j, ca = 1;
    int n, m;
    while(~scanf("%d%d",&n,&m)){
        for (i=1;i<=n;i++) {
            for (j = 1;j <= m;j++) scanf("%d", &map[i][j]);
        }
        for (i = 0;i <= n;i++) A[i][0] = B[i][0] = 0;
        for (i = 0;i <= m;i++) B[0][i] = A[0][i] = 0;
        for (i = 1;i <= n;i++) {
            for (j = 1;j <= m;j++) {
                A[i][j] = A[i-1][j]+A[i][j-1]-A[i-1][j-1]+1ll*map[i][j];
                B[i][j] = B[i-1][j]+B[i][j-1]-B[i-1][j-1]+1ll*map[i][j]*map[i][j];
            }
        }
        makermq(n, m, map);
        scanf("%d", &q);
        int tx, ty;
        printf("Case %d:\n", ca++);
        while (q--) {
            scanf("%d%d", &tx, &ty);
            double ans = -1;
            int ax, ay;
            for (i = 1;i <= n-tx+1;i++) {
                for (j = 1;j <= m-ty+1;j++) {
                    double tm = cal(i, j, tx+i-1, ty+j-1,(tx*ty-1));
                    if (ans == -1 || tm < ans) {
                        ans = tm, ax = i, ay = j;
                    }
                }
            }
            printf("(%d, %d), %.2lf\n", ax, ay, ans);
        }
    }
} 

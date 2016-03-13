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

const double eps = 1e-6;
int n;
double ans[120][120], a[120][120], m[120][120];
bool check()
{
    bool flag = false;
    for (int i = 1; i <= n; i++){
        if (flag) break;
        else
            for (int j = 1; j <= n; j++)
                if (m[i][j] > eps){
                    flag = true;
                    break;
                }
    }
    return flag;
}
void shucheng(double a[][120], double x)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = a[i][j] * x;
}
void jucheng(double c[][120], double a[][120], double b[][120])
{
    double tmp[120][120];
    memset(tmp, 0, sizeof(tmp));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                tmp[i][j] += a[i][k] * b[k][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[i][j] = tmp[i][j];
}
int main()
{
    while(scanf("%d", &n) && n)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%lf", &a[i][j]);
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= n; i++)
            ans[i][i] += 1.0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++){
                ans[i][j] += a[i][j];
                m[i][j] = a[i][j];
            }
        double k = 2.0;
        while(check() || k < 30)
        {
            jucheng(m, m, a);
            shucheng(m, 1.0/k);
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    ans[i][j] += m[i][j];
            k = k + 1.0;
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j < n; j++)
                printf("%.2f ", ans[i][j]);
            printf("%.2f \n", ans[i][n]);
        }
    }
    return 0;
}

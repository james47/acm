#include<cstdio>
#include<cstring>
using namespace std;

const int mo = 10007;
struct matrix{
    int m[2][2];
    matrix operator * (const matrix a) const{
        matrix c;
        memset(c.m, 0, sizeof(c.m));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    c.m[i][j] = (c.m[i][j] + m[i][k] * a.m[k][j]) % mo;
        return c;
    }
} E;
int qmi(int x, int n, int mo)
{
    if (n == 0) return 1;
    if (n == 1) return x;
    int t = qmi(x, n/2, mo);
    if (n & 1) return (((t * t) % mo) * x) % mo;
    else return (t * t) % mo;
}
matrix mqmi(matrix a, int n, int mo)
{
    if (n == 0) return E;
    if (n == 1) return a;
    matrix b = mqmi(a, n / 2, mo);
    if (n & 1)
        return b * b * a;
    else
        return b * b;
}
int f(int n)
{
    if (n == 1) return 2;
    if (n == 2) return 4;
    matrix a;
    a.m[0][0] = a.m[0][1] = a.m[1][0] = 1;
    a.m[1][1] = 0;
    matrix ff = mqmi(a, n-1, mo);
    return (ff.m[1][0] * 4 + ff.m[1][1] * 2) % mo;
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        printf("%d\n", (qmi(2, n, mo) - f(n) + mo) % mo);
    }
    return 0;
}

#include<cstdio>
#include<cmath>
using namespace std;

const int mo = 2006;
int qmi(int x, int n, int mo)
{
        x = x % mo;
        if (n == 1) return x;
        int div = qmi(x, n/2, mo);
        if (n & 1)
                return (((x * div) % mo) * div) % mo;
        else
                return (div * div) % mo;
}
int main()
{
        int n;
        while(scanf("%d", &n) && n)
        {
                printf("%d\n", qmi(n, n, mo));
        }
        return 0;
}

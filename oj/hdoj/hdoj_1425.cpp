#include<cstdio>
#include<cstring>
using namespace std;

const int X = 500000;
bool c[X * 2 + 100];
int main()
{
        int n, m;
        while(scanf("%d %d", &n, &m) != EOF)
        {
                memset(c, false, sizeof(c));
                int x;
                for (int i = 0; i < n; i++)
                {
                        scanf("%d", &x);
                        c[x + X] = true;
                }
                int cnt = 0;
                for (int i = X * 2; i >= 0; i--)
                {
                        if (c[i])
                        {
                                cnt++;
                                printf("%d", i - X);
                                if (cnt == m)
                                {
                                        printf("\n");
                                        break;
                                }
                                else
                                        printf(" ");
                        }
                }
        }
        return 0;
}

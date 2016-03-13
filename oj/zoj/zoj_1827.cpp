#include<cstdio>
#include<cstring>
using namespace std;

char s[100];
int num[10];
bool dfs(int sum)
{
        if (sum >= 31) return 0;
        for (int i = 1; i <= 6; i++)
        if (num[i] && sum + i <= 31)
        {
                num[i]--;
                if (dfs(sum + i) == 0)
                {
                        num[i]++;
                        return 1;
                }
                num[i]++;
        }
        return 0;
}
int main()
{
        while(scanf("%s", s) != EOF)
        {
                int len = strlen(s);
                for (int i = 1; i <= 6; i++)
                        num[i] = 4;
                int tot = 0;
                for (int i = 0; i < len; i++)
                {
                        tot += s[i] - '0';
                        num[s[i] - '0'] --;
                }
                printf("%s ", s);
                if (dfs(tot))
                {
                        if (len & 1)
                                puts("B");
                        else
                                puts("A");
                }
                else
                {
                        if (len & 1)
                                puts("A");
                        else
                                puts("B");
                };
        }
        return 0;
}

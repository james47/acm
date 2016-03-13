#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <map>
#define MAXN 10
#define INF 1LL<<61
#define C 16381
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b)
{
    return b ? gcd(b, a % b) : a;
}

LL multi(LL a, LL b, LL m)
{
     LL ans = 0;
     while(b)
     {
         if(b & 1)
         {
             ans = (ans + a) % m;
             b--;
         }
         b >>= 1;
         a = (a + a) % m;
     }
     return ans;
}

LL quick_mod(LL a, LL b, LL m)
{
     LL ans = 1;
     a %= m;
     while(b)
     {
         if(b & 1)
         {
             ans = multi(ans, a, m);
             b--;
         }
         b >>= 1;
         a = multi(a, a, m);
     }
     return ans;
}

bool Miller_Rabin(LL n)
{
    if(n == 2) return true;
    if(n < 2 || !(n & 1)) return false;
    LL a, m = n - 1, x, y;
    int k = 0;
    while((m & 1) == 0)
    {
        k++;
        m >>= 1;
    }
    for(int i = 0; i < MAXN; i++)
    {
        a = rand() % (n - 1) + 1;
        x = quick_mod(a, m, n);
        for(int j = 0; j < k; j++)
        {
            y = multi(x, x, n);
            if(y == 1 && x != 1 && x != n - 1) return false;
            x = y;
        }
        if(y != 1) return false;
    }
    return true;
}

LL Pollard_rho(LL n, LL c)
{
     LL x, y, d, i = 1, k = 2;
     y = x = rand() % (n - 1) + 1;
     while(true)
     {
         i++;
         x = (multi(x, x, n) + c) % n;
         d = gcd((y - x + n) % n, n);
         if(1 < d && d < n) return d;
         if(y == x) return n;
         if(i == k)
         {
             y = x;
             k <<= 1;
         }
     }
}
LL fac[555];
int cnt;
map<LL, int>mp;
void find(LL n, int c)
{
     if(n == 1) return;
     if(Miller_Rabin(n))
     {
         mp[n]++;
         return ;
     }
     LL p = n;
     LL k = c;
     while(p >= n) p = Pollard_rho(p, c--);
     find(p, k);
     find(n / p,k);
}

int main()
{
    LL a, b;
    while(scanf("%lld%lld", &a, &b) != EOF)
    {
        cnt = 0;
        LL tmp = b / a;
        if(a == b)
        {
            printf("%lld %lld\n", a, b);
            continue;
        }
        mp.clear();
        find(tmp, C);
        cnt = 0;
        for(map<LL, int>:: iterator it = mp.begin(); it != mp.end(); it++)
        {
            LL t = 1;
            for(int j = 0; j < it -> second; j++)
                t = t * (it -> first);
            fac[cnt++] = t;
        }
        //for(int i = 0; i < cnt; i++)
           // printf("%lld\n", fac[i]);
        LL ansa = INF, ansb = INF;
        for(int i = 0; i < (1 << cnt); i++)
        {
            LL ta = 1;
            for(int j = 0; j < cnt; j++)
                if(i & (1 << j))
                    ta *= fac[j];
            if(ansa + ansb > ta + b / a / ta)
                ansa = ta, ansb = b / a / ta;
        }
        if(ansa > ansb) swap(ansa, ansb);
        printf("%lld %lld\n", ansa * a, ansb * a);
    }
	return 0;
}

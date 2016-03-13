#include<iostream>
#include<cstdio>
using namespace std;

int a[10];
int main()
{
    //freopen("a.in","r",stdin);
    //freopen("b.out","w",stdout);
    while (1)
    {
        int ans = 0;
        for (int i = 1;i <= 6;i++)
        {
            cin >> a[i];
            ans += a[i];
        }
        if (ans == 0) break;
        ans = a[4] + a[5] + a[6];
        a[2] -= a[4] * 5;
        a[1] -= a[5] * 11;
        ans += a[3]/4;
        a[3] %= 4;
        switch (a[3])
        {
            case 3: a[2] -= 1;a[1] -= 5; break;
            case 2: a[2] -= 3;a[1] -= 6; break;
            case 1: a[2] -= 5;a[1] -= 7; break;
            case 0: ans--;
        }
        ans++;
        if (a[2] > 0)
        {
            ans += a[2]/9;
            if (a[2] % 9 != 0)
            {
                ans++;
                a[1] -= 36 - (a[2] % 9) * 4;
            }
        }
        else
            a[1] += a[2] * 4;
        if (a[1] > 0)
        {
            ans += a[1]/36;
            if (a[1] % 36 != 0) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

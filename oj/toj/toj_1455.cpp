#include<cstdio>
#include<cstring>
using namespace std;

const int N = 500010;
long long ans = 0;
int a[N], b[N];
void combine(int a[], int tmp[], int l, int m, int r)
{
        for (int i = l; i <= r; i++)
                tmp[i] = a[i];
        int p = l, p1 = l, p2 = m + 1;
        while(p1 <= m && p2 <= r)
        {
                if (tmp[p1] <= tmp[p2])
                {
                        a[p++] = tmp[p1++];
                }
                else
                {
                        a[p++] = tmp[p2++];
                        ans += m - p1 + 1;
                }
        }
        while(p1 <= m) a[p++] = tmp[p1++];
        while(p2 <= r) a[p++] = tmp[p2++];
        return;
}
void mergesort(int a[], int l, int r)
{
        if (l == r)
                return;
        int m = (l + r) >> 1;
        mergesort(a, l, m);
        mergesort(a, m+1, r);
        combine(a, b, l, m, r);
        return;
}
int main()
{
        int n;
        while(scanf("%d", &n) && n)
        {
                for (int i = 0; i < n; i++)
                {
                        scanf("%d", &a[i]);
                }
                ans = 0;
                mergesort(a, 0, n - 1);
                printf("%lld\n", ans);
        }
        return 0;
}

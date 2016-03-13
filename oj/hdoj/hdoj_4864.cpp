#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

const int maxn = 100100;
int n, m, ans1;
long long ans2;
struct stuff{
	int t, d;
} a[maxn], b[maxn];
map<int, int> cnt;
bool cmp(stuff a, stuff b)
{
	if (a.t == b.t) return a.d > b.d;
	return a.t > b.t;
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%d %d", &a[i].t, &a[i].d);
		for (int i = 0; i < m; i++)
			scanf("%d %d", &b[i].t, &b[i].d);
		sort(a, a+n, cmp);
		sort(b, b+m, cmp);
		ans1 = 0, ans2 = 0;
		int j = 0;
		cnt.clear();
		map<int, int>::iterator it;
		for (int i = 0; i < m; i++)
		{
			while(j < n && a[j].t >= b[i].t){
				cnt[a[j].d]++;
				j++;
			}
			it = cnt.lower_bound(b[i].d);
			if (it != cnt.end()){
				ans1 ++;
				ans2 += 500 * b[i].t + 2 * b[i].d;
				cnt[it->first] --;
				if (cnt[it->first] == 0)
					cnt.erase(it);
			}
		}
		printf("%d %I64d\n", ans1, ans2);
//		printf("%d %lld\n", ans1, ans2);
	}
	return 0;
}

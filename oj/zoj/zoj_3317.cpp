#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{
	int b, e, id;
} a[110];
int ans[110], l[110];
int n, m;
bool cmp(node x, node y)
{
	return x.b < y.b;
}
bool cmp1(node x, node y)
{
	return x.id < y.id;
}
int main()
{
	while(scanf("%d %d", &n, &m) && n+m)
	{
		for (int i = 0; i < n; i++){
			scanf("%d %d", &a[i].b, &a[i].e);
			a[i].id = i;
		}
		sort(a, a+n, cmp);
		memset(l, 0, sizeof(l));
		for (int i = 0; i < n; i++){
			int j;
			for (j = 1; j <= m; j++) if (l[j] <= a[i].b) break;
			if (j > m) ans[a[i].id] = 0;
			else{
				ans[a[i].id] = j;
				l[j] = a[i].e;
			}

		}
		sort(a, a+n, cmp1);
		for (int i = 0; i < n; i++)
			printf("%d\n", ans[i]);
	}
	return 0;
}

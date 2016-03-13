#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 1001000;
struct kart{
	int v, w, lv;
} a[101000];
int lv[1001000], sizelv[101000];
bool cmp(kart a, kart b)
{
	if (a.v == b.v) return a.w > b.w;
	return a.v > b.v;
}
bool cmp1(kart a, kart b)
{
	if (a.lv != b.lv) return a.lv < b.lv;
	if (a.v != b.v) return a.v < b.v;
	return a.w < b.w;
}
int lowbit(int x)
{
	return x & -x;
}
int query(int x)
{
	int ret = 0;
	for (int i = x; i <= maxn; i += lowbit(i))
		ret = max(ret, lv[i]);
	return ret;
}
void update(int x, int val)
{
	for (int i = x; i > 0; i -= lowbit(i))
		lv[i] = max(lv[i], val);
}
int n, maxlv;
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++) scanf("%d %d", &a[i].v, &a[i].w);
		sort(a, a+n, cmp);
		int maxlv = 0;
		memset(sizelv, 0, sizeof(sizelv));
		memset(lv, 0, sizeof(lv));
		for (int i = 0; i < n; i++){
			if (i != 0){
				if (a[i].v == a[i-1].v && a[i].w == a[i-1].w){
					a[i].lv = a[i-1].lv;
					sizelv[a[i].lv] ++;
					continue;
				}
			}
			a[i].lv = query(a[i].w+1) + 1;
			sizelv[a[i].lv] ++;
			maxlv = max(maxlv, a[i].lv);
			update(a[i].w+1, a[i].lv);
		}
		sort(a, a+n, cmp1);
		int p = 0;
		for (int i = 1; i <= maxlv; i++){
			printf("%d:", sizelv[i]);
			for (int j = 0; j < sizelv[i]; j++){
				printf(" (%d,%d)", a[p].v, a[p].w);
				p++;
			}
			printf("\n");
		}
	}
	return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
int T;
void build(int x, LL l, LL r)
{
	tree[x].f = 0;
	if (l == r){
		tree[x].v = l;
		tree[x].sum = 1;
		return;
	}
	LL mid = l + r >> 1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);
	tree[x].sum = tree[x<<1].sum + tree[x<<1|1].sum;
}
int main()
{
	scanf("%d", &T);
	int cas = 0;
	while(T--)
	{
		scanf("%d %d", &n, &m);
		printf("Case #%d:\n", ++ cas);
		build(1, 1, n);
		char tp;
		LL ll, rr, b, e, sum1, sum2;
		for (int i = 0; i < m; i++){
			scanf("%c%lld%lld", &tp, &b, &e);
			ll = find(b, sum1);
			rr = find(e, sum2);
			if (tp == 'D'){
				update();
			}
			else{
				query();
			}
		}
	}
	return 0;
}

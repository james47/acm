#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
int n;
int a[4100], b[4100], c[4100], d[4100];
LL B[16000100];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d %d %d", a+i, b+i, c+i, d+i);
	int size = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			B[size++] = (LL)c[i] + d[j];
	sort(B, B+size);
	LL ans = 0, cur;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			cur = (LL) a[i] + b[j];
			LL *b, *e;
			b = lower_bound(B, B+size, -cur);
			e = upper_bound(B, B+size, -cur);
			ans += e - b;
		}
	printf("%lld\n", ans);
	return 0;
}

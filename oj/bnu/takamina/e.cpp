#include<cstdio>
#include<algorithm>
using namespace std;

long long a[3];
int main()
{
	scanf("%I64d %I64d %I64d", a+0, a+1, a+2);
	sort(a, a+3);
	long long ans;
	if ((a[0] + a[1]) * 2 < a[2]) ans = a[0] + a[1];
	else ans = (a[0] + a[1] + a[2]) / 3;
	printf("%I64d\n", ans);
	return 0;
}

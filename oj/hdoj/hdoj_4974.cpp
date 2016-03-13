#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T, n, t, maxn;
long long sum;
int main()
{
	scanf("%d", &T);
	int cas = 0;
	while(T--)
	{
		sum = maxn = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%d", &t);
			sum = sum + t;
			maxn = max(maxn, t);
		}
		sum = (sum+1)/2;
		long long ans;
		if (maxn >= sum) ans = maxn;
		else ans = sum;
		printf("Case #%d: %lld\n", ++cas, ans);
	}
	return 0;
}

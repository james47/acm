#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T;
long long a, b, s, c[3], d[3], e[3], ans;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld", &s);
		for (int i = 0; i < 3; i++){
			scanf("%lld.%lld", &a, &b);
			c[i] = a * 100 + b;
		}

		ans = 0;
		d[0] = d[1] = d[2] = 0;
		e[0] = e[1] = e[2] = 0;
		for (int i = 1; i <= s; i++){
			int k = min_element(e, e+3) - e;
			++d[k];
			e[k] = d[k] * c[k] / 100;
			ans = max(ans, *min_element(e, e+3) - i);
		}
		printf("%lld\n", ans + s);
	}
	return 0;
}

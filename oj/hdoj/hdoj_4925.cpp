#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T, n, m;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &n, &m);
		if (n > m) swap(n, m);
		if (m == 1){
			puts("1");
			continue;
		}
		if (n == 1) printf("%d\n", 2 * (m-1));
		else printf("%d\n", 8 * (m-1) * (n-1));
	}
	return 0;
}

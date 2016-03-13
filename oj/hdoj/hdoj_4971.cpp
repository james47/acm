#include<cstdio>
#include<cstring>
using namespace std;

int sou, tar, n, m, T, cas = 0;

void init()
{
	scanf("%d %d", &n, &m);
	sou = 0; tar = n+m+1;
	int w;
	for (int i = 1; i <= n; i++){
		scanf("%d", &w);

	}
}
int maxflow()
{
	int ret = 0;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		init();
		printf("Case #%d: %d\n", ++ cas, sum - maxflow());
	}
	return 0;
}

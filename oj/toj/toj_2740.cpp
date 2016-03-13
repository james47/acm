#include<cstdio>
#include<cstring>
using namespace std;

int n, d, x;
int son[100100];
int main()
{
	while(scanf("%d %d", &n, &d) != EOF)
	{
		memset(son, 0, sizeof(son));
		for (int i = 0; i < n; i++){
			scanf("%d", &x);
			son[x] ++;
		}
		int ans = 0;
		for (int i = 0; i <= n; i++){
			x = son[i];
			while(x>d){
				ans += x/d;
				x = x/d + x%d;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

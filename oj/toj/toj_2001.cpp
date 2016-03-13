#include<cstdio>
#include<cstring>
using namespace std;

int T, n;
char str[30];
int main()
{
	scanf("%d", &T);
	int cas = 0;
	while(T--)
	{
		scanf("%d", &n);
		int cnt = 0;
		for (int i = 0; i < n; i++){
			scanf("%s", str);
			if (strcmp(str, "sheep") == 0) cnt ++;
		}
		if (cas) printf("\n");
		printf("Case %d: This list contains %d sheep.\n", ++cas, cnt);
	}
	return 0;
}

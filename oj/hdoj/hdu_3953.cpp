#include<cstdio>
#include<cstring>
using namespace std;

int T;
char a[300], b[300];
int main()
{
	scanf("%d", &T);
	int cas = 0;
	while(T--){
		scanf("%s %s", a, b);
		int len = strlen(a);
		int ans = 0;
		for (int i = 0; i < len; i++)
			ans += a[i] - '0';
		len = strlen(b);
		for (int i = 0; i < len; i++)
			ans += b[i] - '0';
		printf("Case %d: %d\n", ++ cas, ans);
	}
	return 0;
}

#include<cstdio>
#include<cstring>
using namespace std;

char s[30];
int main()
{
	while(scanf("%s", s) != EOF)
	{
		long long ans = 0, tmp = 1;
		for (int i = strlen(s) - 1; i >= 0; i --){
			int x;
			if ('0' <= s[i] && s[i] <= '9') x = (s[i] - '0');
			else x = (s[i] - 'A' + 10);
			ans += tmp * x;
			tmp *= 16ll;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

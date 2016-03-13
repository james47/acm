#include<cstdio>
#include<cstring>
using namespace std;

int T, n, k;
char* s[2] = {"first", "second"};
int main()
{
	scanf("%d", &T);
	int cas = 0;
	while(T--){
		scanf("%d %d", &n, &k);
		int ans = 0;
		if (k == 1 && !(n&1)) ans = 1;
		if (k > 1 && n > k) ans = 1;
		printf("Case %d: %s\n", ++cas, s[ans]);
	}
	return 0;
}

#include<cstdio>
#include<cstring>
using namespace std;

int n;
char buf[110];
int main()
{
	scanf("%d%s", &n, buf);
	int ans = 0;
	while(buf[ans] == '1') ans++;
	if (ans != n) ans++;
	printf("%d\n", ans);
	return 0;
}

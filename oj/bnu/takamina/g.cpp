#include<cstdio>
#include<cstring>
using namespace std;

int n, p, x;
bool v[110];
int main()
{
	scanf("%d", &n);
	memset(v, 0, sizeof(bool)*(n+1));
	for (int i = 0; i < 2; i++){
		scanf("%d", &p);
		for (int i = 0; i < p; i++){
			scanf("%d", &x);
			v[x] = true;
		}
	}
	bool flag = true;
	for (int i = 1; i <= n; i++) if (!v[i]) flag = false;
	if (flag) puts("I become the guy.");
	else puts("Oh, my keyboard!");
	return 0;
}

#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 10000;
bool a[maxn+100];
int f[maxn+100];
int b, e;
void create_prime()
{
	memset(a, true, sizeof(a));
	a[0] = a[1] = false;
	memset(f, 0, sizeof(f));
	for (int i = 2; i <= maxn; i++){
		if (a[i]){
			f[i] = f[i-1] + 1;
			for (int j = 2 * i; j <= maxn; j += i) a[j] = false;
		}
		else f[i] = f[i-1];
	}
}
int main()
{
	create_prime();
	while (scanf("%d %d", &b, &e) != EOF)
	{
		int tot = f[e] - f[b-1];
		if (a[tot]) puts("YES");
		else puts("NO");
	}
	return 0;
}

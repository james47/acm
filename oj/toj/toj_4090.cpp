#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 300000;
int n, size;
bool a[maxn+100];
int p[maxn];
void create_prime()
{
	size = 1;
	memset(a, true, sizeof(a));
	for (int i = 2; i <= maxn; i++){
		if (a[i]){
			p[size++] = i;
			for (int j = 2 * i; j <= maxn; j += i) a[j] = false;
		}
	}
}
int main()
{
	create_prime();
	while(scanf("%d", &n) != EOF)
	{
		printf("%d%d\n", p[n*2-1], p[n*2]);
	}
	return 0;
}

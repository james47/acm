#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 1000000;
int n, size;
int p[maxn];
bool a[maxn+100];
void create_prime()
{
	size = 0;
	memset(a, true, sizeof(a));
	a[0] = a[1] = false;
	for (int i = 2; i <= maxn; i++){
		if (a[i]) p[size++] = i;
		for (int j = 0; j < size; j ++){
			if (p[j] * i > maxn) break;
			a[p[j]*i] = false;
			if (i % p[j] == 0) break;
		}
	}
}
void f(int n, int &t1, int &t2)
{
	for (int i = 0; i < size; i++) if (a[n-p[i]]){
		t1 = p[i];
		t2 = n-p[i];
		return;
	}
}
int main()
{
	create_prime();
	while(scanf("%d", &n), n)
	{
		int t1, t2;
		f(n, t1, t2);
		printf("%d = %d + %d\n", n, t1, t2);
	}
	return 0;
}

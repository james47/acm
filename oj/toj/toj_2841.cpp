#include<cstdio>
#include<cstring>
using namespace std;

int n, size;
int a[100];
int main()
{
	while(scanf("%d", &n))
	{
		if (!n) break;
		size = 0;
		while(n){
			a[size++] = n & 1;
			n >>= 1;
		}
		for (int i = 0; i < size; i++) n = (n << 1) + a[i];
		printf("%d\n", n);
	}
	return 0;
}

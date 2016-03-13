#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<ctime>
#include<string>
using namespace std;

int n, m;
int x[110];
long long A[110], B[110];
long long b(int id)
{
	if (B[id] != -1) return B[id];
	if (x[id] == 1) return A[id];
	if (id == 1) return (x[id]*2-1) % m;
	return (((A[id-1]*2)%m + ((long long)x[id]*2)%m)%m + b(id-1))%m;
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		memset(B, -1, sizeof(B));
		A[0] = 0;
		for (int i = 1; i <= n; i++){
			scanf("%d", x+i);
			A[i] = (A[i-1] * 2 + x[i]) % m;
		}
		printf("%lld\n", b(n));
	}
	return 0;
}

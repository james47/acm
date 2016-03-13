#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 3000010;
int phi[maxn+5];
long long sum[maxn+5];
int b, e;
void get_phi()
{
	memset(phi, 0, sizeof(phi));
	phi[1] = 1;
	sum[0] = 0;
	sum[1] = 1;
	for (int i = 2; i < maxn; i++){
		if (!phi[i]){
			phi[i] = i - 1;
			for (int j = 2 * i; j < maxn; j += i){
				if (!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
		sum[i] = sum[i-1] + phi[i];
	}
}
int main()
{
	get_phi();
	while(scanf("%d %d", &b, &e) != EOF)
	{
		printf("%lld\n", sum[e] - sum[b-1]);
	}
	return 0;
}

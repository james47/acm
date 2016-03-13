#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 3000010;
long long sum[maxn+5];
int b, e;
void get_phi()
{
	memset(sum, 0, sizeof(sum));
	sum[1] = 1;
	for (int i = 2; i < maxn; i++){
		if (!sum[i]){
			sum[i] = i - 1;
			for (int j = 2 * i; j < maxn; j += i){
				if (!sum[j]) sum[j] = j;
				sum[j] = sum[j] / i * (i - 1);
			}
		}
		sum[i] = sum[i-1] + sum[i];
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

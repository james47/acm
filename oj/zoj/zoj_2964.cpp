#include<cstdio>
#include<cstring>
using namespace std;

const int ps = 100001;
int mpf[ps+5], prime[ps+5];
int pn = 0;
int T, a, z;

void getprime(){
	memset(mpf, 0, sizeof(mpf));
	for (int i = 2; i < ps; i ++){
		if (mpf[i] == 0) prime[pn++] = i;
		for (int j = 0; j < pn && i*prime[j] < ps && (prime[j] <= mpf[i]||mpf[i] == 0); j++)
			mpf[i*prime[j]] = prime[j];
	}
}
int phi(int x){
	int ret = 1;
	for (int i = 0; i < pn; i++){
		if (x % prime[i] == 0){
			int tmp = prime[i] - 1;
			x /= prime[i];
			while(x % prime[i] == 0){
				tmp *= prime[i];
				x /= prime[i];
			}
			ret *= tmp;
		}
	}
	if (x > 1){
		ret *= x - 1;
	}
	return ret;
}
int pow_mod(int a, int n){
	if (n == 0) return 1;
	if (n == 1) return a % z;
	int tmp = pow_mod(a, n/2);
	if (n & 1) return (long long) tmp * tmp % z * a % z;
	return (long long) tmp * tmp % z;
}
int cal(int a, int x){
	int ans = x;
	for (int i = 1; i * i <= x; i++){
		if (x % i == 0){
			int tmp = pow_mod(a, i);
			if (tmp == 1) return i;
			tmp = pow_mod(a, x/i);
			if (tmp == 1) ans = x/i;
		}
	}
	return ans;
}
int main()
{
	getprime();
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &a, &z);
		int ph = phi(z);
		ph = cal(a, ph);
		printf("%lld\n", (long long)ph * 6 + 3);
	}
	return 0;
}

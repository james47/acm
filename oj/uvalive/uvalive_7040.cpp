/*************************************************************************
    > File Name: uvalive_7040.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sat Aug  8 08:47:40 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int mod = (int)1e9+7;
int pow_mod(int a, int exp){
	int ret = 1;
	while(exp){
		if (exp&1) ret = (long long)ret * a % mod;
		a = (long long)a * a % mod;
		exp >>= 1;
	}
	return ret;
}
int c[(int)1e6+100];
int inv[(int)1e6+100];
int cal(int n, int m, int k){
	if (k == 1 && n == 1) return m;
	if (k == 1 && n > 1) return 0;
	int ret = 1, lim = min(k, m - k);
	for (int i = 1; i <= lim; i++) ret = (long long)ret * (m-i+1) % mod * inv[i] % mod;
	c[0] = 1;
	for (int i = 1; i <= k; i++) c[i] = (long long)c[i-1] * (k-i+1) % mod * inv[i] % mod;
	int tmp, tot = (long long)k * pow_mod(k-1, n-1) % mod;
	for (int i = 1; i+1 < k; i++){
		tmp = (long long)c[i] * (k-i) % mod * pow_mod(k-i-1, n-1) % mod;
		if (i&1){
			tot = tot - tmp;
			if (tot < 0) tot += mod;
		}
		else{
			tot = tot + tmp;
			if (tot >= mod) tot -= mod;
		}
	}
	ret = (long long)ret * tot % mod;
	return ret;
}
void init(){
	inv[1] = 1;
	for (int i = 2; i <= 1000000; i++){
		inv[i] = (long long)(mod - mod/i) * inv[mod % i] % mod;
	}
}
int T, n, m, k;
int main()
{
	init();
	scanf("%d", &T); int cas = 0;
	while(T--){
		scanf("%d %d %d", &n, &m, &k);
		printf("Case #%d: %d\n", ++cas, cal(n, m, k));
	}
	return 0;
}

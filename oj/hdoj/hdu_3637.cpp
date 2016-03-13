/*************************************************************************
    > File Name: hdu_3637.cpp
    > Author: james47
    > Mail: 
    > Created Time: Mon Aug 10 09:38:12 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long ll;
ll a, b, c, d, x, y;
/*
void work1(ll a, ll b, ll c, ll d, ll& x, ll& y, int dep){
	if (d == 0){
		x = a/b + 1; y = 1; return;
	}
	assert(b != 0);
	if (a/b + 1 <= (c+d-1)/d - 1){
		x = a/b + 1; y = 1; return;
	}
	if (dep & 1){
		ll q = c / d, r = c % d;
		work1(d, r, b, a-q*b, y, x, dep+1);
		x += q * y;
	}
	else{
		ll q = a / b, r = a % b;
		work1(d, c-q*d, b, r, y, x, dep+1);
		x += q * y;
	}
}
*/
void work(ll a, ll b, ll c, ll d, ll &x, ll &y, int dep){
	if (a % b == 0){
		ll k = a/b;
		y = d/(c-k*d) + 1;
		x = k*y+1;
		return;
	}
	long long k1 = a/b+1, k2 = c/d;
	if (c%d==0) k2 --;
	if (k1 <= k2){
		y = 1; x = k1; return;
	}
	long long k = a/b;
	work(d, c-k*d, b, a%b, y, x, dep);
	x += k * y;
}
ll gcd(ll a, ll b){ return b==0? a: gcd(b, a % b); }
void get(ll a, ll b, ll c, ll d, ll& e, ll& f){
	ll k = gcd(b, d), t = b/k*d;
	f = t; e = a*(t/b) + c*(t/d);
}
void gg(char *str, ll &a, ll &b){
	int len = strlen(str);
	long long k = 0, k2 = 0, k3 = 1;
	int i;
	for (i = 0; i < len && str[i] != '.'; i++){
		k = k * 10 + str[i] - '0';
	}
	if (i >= len){
		a = k, b = 1;
		return;
	}
	i++;
	for (; i < len && str[i] != '['; i++){
		k2 = k2*10 + str[i] -'0';
		k3 *= 10;
	}
	get(k, 1, k2, k3, a, b);
	if (str[i] != '[') return;
	i ++;
	k = k3;
	k2 = k3 = 0;
	for (; i < len && str[i] != ']'; i++){
		k2 = k2 * 10 + str[i] - '0';
		k3 = k3 * 10 + 9;
	}
	get(a, b, k2, k3*k, a, b);
}
int T, cas = 0;
char str[100];
int main()
{
	long long a, b, c, d, x, y;
	scanf("%d", &T);
	while(T--){
		scanf("%s", str); gg(str, a, b);
		scanf("%s", str); gg(str, c, d);
		work(a, b, c, d, x, y, 0);
		ll gcdxy = gcd(x, y);
		x /= gcdxy, y /= gcdxy;
		printf("Case %d: %lld/%lld\n", ++cas, x, y);
		/*
		work1(a, b, c, d, x, y, 0);
		gcdxy = gcd(x, y);
		x /= gcdxy, y /= gcdxy;
		printf("Case %d: %lld/%lld\n", ++cas, x, y);
		*/
	}
	return 0;
}

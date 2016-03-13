/*************************************************************************
    > File Name: hdu_3637.cpp
    > Author: james47
    > Mail: 
    > Created Time: Mon Aug 10 14:40:24 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
ll a, b, c, d, x, y;
char buf[100];

ll gcd(ll a, ll b){ return b? gcd(b, a%b): a; }
void add(ll& x, ll& y, ll a, ll b){
	/*
	ll tmp = y;
	y = y * b; x = x * b + a * tmp;
	tmp = gcd(x, y);
	x /= tmp, y /= tmp;
	*/
	ll c = x, d = y, g = gcd(b, d);
	y = b / g * d;
	x = d / g * a + b / g * c;
	g = gcd(x, y);
	x /= g, y /= g;
}
void work(char* buf, ll& x, ll& y){
	int len = strlen(buf), i;
	ll tmp = 0, tmp1;
	for (i = 0; buf[i] != '.' && i < len; i++){ tmp = tmp * 10 + buf[i] - '0'; }
	x = tmp, y = 1;
	add(x, y, 0, 1);
	if (i == len) return;
	for (i++, tmp = 0, tmp1 = 1; buf[i] != '[' && i < len; i++){
		tmp = tmp * 10 + buf[i] - '0';
		tmp1 = tmp1 * 10;
	}
	add(x, y, tmp, tmp1);
	if (i == len) return;
	ll tmp2 = tmp1;
	for (i++, tmp = 0, tmp1 = 0; buf[i] != ']'; i++){
		tmp = tmp * 10 + buf[i] - '0';
		tmp1 = tmp1 * 10 + 9;
	}
	tmp1 *= tmp2;
//	printf("%lld %lld\n", tmp, tmp1);
	add(x, y, tmp, tmp1);
}
bool check(ll a, ll b, ll c, ll d, ll y){
	ll x1 = a*y/b+1, x2 = (c*y-1)/d;
	/*
	x2 = c*y/d;
	if (c*y%d==0) x2--;
	*/
	if (x1 <= x2) return 1;
	return 0;
}

int T, cas = 0;
int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%s", buf); work(buf, a, b);
		scanf("%s", buf); work(buf, c, d);
//		printf("%lld %lld %lld %lld\n", a, b, c, d);
		for (y = 1; check(a, b, c, d, y) == false; y++);
		x = a*y/b + 1;
		printf("Case %d: %lld/%lld\n", ++cas, x, y);
	}
	return 0;
}

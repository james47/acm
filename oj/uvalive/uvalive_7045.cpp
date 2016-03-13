/*************************************************************************
    > File Name: uvalive_7045.cpp
    > Author: james47
    > Mail: 
    > Created Time: Mon Jul 27 19:50:08 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
int T, cas;
ll a, b;

ll cal(ll a, ll b){
	if (b == 0) return 1;
	else return a / b + cal(b, a % b);
}

int main()
{
	scanf("%d", &T); cas = 0;
	while(T--){
		scanf("%lld %lld", &a, &b);
		ll ans = cal(a, b);
		if (a == 0 || b == 0)
			if (a + b != 0) ans = 2;
		printf("Case #%d: %lld\n", ++cas, ans);
	}
	return 0;
}

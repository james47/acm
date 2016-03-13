/*************************************************************************
    > File Name: toj_4129.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sat Jun 20 01:02:50 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n;
unsigned long long ans, tmp, x, b[100];
int main()
{
	scanf("%d", &n);
	memset(b, 0, sizeof(b));
	ans = 0;
	while(n--){
		scanf("%llu", &x);
		int i;
		for (i = 0; i < 64; i++)
			if ((1ll << i) & x) x ^= b[i];
		if (x){
			for (i = 63; i > 0; i--)
				if ((1ll << i) & x) break;
			b[i] = x;
			for (int j = 0; j < 64; j++)
				if (i != j && (b[j] & (1ll << i))) b[j] ^= b[i];
			tmp = 0;
			for (int j = 0; j < 64; j++)
				tmp ^= b[j];
			ans = max(ans, tmp);
		}
		printf("%llu\n", ans);
	}
	return 0;
}

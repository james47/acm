/*************************************************************************
    > File Name: d.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sat Aug  8 12:10:43 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int T, n, q, cas = 0;
int f[10010], num[10010], t[10010];
char buf[10];
int getf(int x){
	if (x == f[x]) return x;
	int tmp = f[x];
	f[x] = getf(f[x]);
	t[x] = t[tmp] + t[x];
	return f[x];
}
int main()
{
	scanf("%d", &T);
	while(T--){
		printf("Case %d:\n", ++cas);
		scanf("%d %d", &n, &q);
		for (int i = 1; i <= n; i++){ f[i] = i; num[i] = 1; t[i] = 0; }
		int x, y, fx, fy;
		while(q--){
			scanf("%s", buf);
			if (buf[0] == 'T'){
				scanf("%d %d", &x, &y);
				fx = getf(x), fy = getf(y);
				f[fx] = fy;
				t[fx] ++; num[fy] += num[fx];
			}
			else{
				scanf("%d", &x);
				int fa = getf(x);
				printf("%d %d %d\n", f[fa], num[fa], t[x]);
			}
		}
	}
	return 0;
}

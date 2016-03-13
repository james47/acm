/*************************************************************************
  > File Name: a.cpp
  > Author: james47
  > Mail: 
  > Created Time: Wed Jul 15 13:01:25 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct P{
	int x, a;
} p[1100];
bool cmp(P a, P b){
	return a.x < b.x;
}

int n;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d %d", &p[i].x, &p[i].a);
	}
	p[n].x = 0, p[n].a = 0; n++;
	sort(p, p+n, cmp);
	int st;
	for (st = 0; st < n; st++){
		if (p[st].x == 0) break;
	}
	int ans = 0;
	int i, j;
	for (i = st+1, j = st-1; i < n && j >= 0; i++, j--){
		ans = ans + p[i].a + p[j].a;
	}
	if (i < n){
		ans += p[i].a;
	}
	else if (j >= 0){
		ans += p[j].a;
	}
	printf("%d\n", ans);
	return 0;
}

/*************************************************************************
    > File Name: c.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sat Aug  8 12:51:58 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct rec{
	int x1, y1, x2, y2, val;
	rec(){}
	rec(int _x1, int _y1, int _x2, int _y2, int _val):x1(_x1), y1(_y1), x2(_x2), y2(_y2), val(_val){}
} r[25];
bool cmp(rec a, rec b){
	return a.val < b.val;
}
int T, n;
/*
long long solve(rec x, int i){
	if (dep == n) return (long long)(x.x2 - x.x1) * (x.y2 - x.y1) * x.val;
	long long ret = 0;
	if (r[i].x1 <= x.x1 && r[i].y1 <= x.y1 && x.x2 <= r[i].x2 && x.y2 <= r[i].y2) return 0;
	return ret;
}
*/
long long ans;
void solve(rec x, int i){
	while(i < n && (x.x1 >= r[i].x2 || x.x2 <= r[i].x1 || x.y1 >= r[i].y2 || x.y2 <= r[i].y1)) i++;
	if (i == n){
		//printf("%d %d %d %d %d\n", x.x1, x.y1, x.x2, x.y2, x.val);
		ans += (long long)(x.x2 - x.x1) * (x.y2 - x.y1) * x.val;
		return;
	}
	if (x.x1 <= r[i].x1) {solve(rec(x.x1, x.y1, r[i].x1, x.y2, x.val), i+1); x.x1 = r[i].x1;}
	if (r[i].x2 <= x.x2) {solve(rec(r[i].x2, x.y1, x.x2, x.y2, x.val), i+1); x.x2 = r[i].x2;}
	if (x.y1 <= r[i].y1) {solve(rec(x.x1, x.y1, x.x2, r[i].y1, x.val), i+1); x.y1 = r[i].y1;}
	if (r[i].y2 <= x.y2) {solve(rec(x.x1, r[i].y2, x.x2, x.y2, x.val), i+1); x.y2 = r[i].y2;}
}
int main()
{
	scanf("%d", &T);
	int cas = 0;
	while(T--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%d %d %d %d %d", &r[i].x1, &r[i].y1, &r[i].x2, &r[i].y2, &r[i].val);
		}
		sort(r, r+n, cmp);
		ans = 0;
		for (int i = 0; i < n; i++) solve(r[i], i+1);
		//printf("Case %d: %I64d\n", ans);
		printf("Case %d: %lld\n", ++cas, ans);
	}
	return 0;
}

/*************************************************************************
    > File Name: c.cpp
    > Author: james47
    > Mail: 
    > Created Time: Thu Sep 17 01:17:51 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 201000;
const double inf = 1e15;
int n;
int a[maxn];
double sum[maxn];

double cal(double x){
	double ret = -1, tmin = 0, tmax = 0;
	sum[0] = 0;
	for (int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + a[i] - x;
		double tmp = fabs(sum[i] - tmin);
		if (tmp > ret) ret = tmp;
		tmp = fabs(sum[i] - tmax);
		if (tmp > ret) ret = tmp;
		tmin = min(tmin, sum[i]);
		tmax = max(tmax, sum[i]);
	}
	return ret;
}
int main()
{
	scanf("%d", &n);
	double tans = -1; bool neg = false;
	double tmin = 0, tmax = 0;
	sum[0] = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", a+i);
		sum[i] = sum[i-1] + a[i];
		double tmp = fabs(sum[i] - tmin);
		if (tmp > tans){
			tans = tmp;
			if (sum[i] - tmin < 0){ neg = true; }
			else neg = false;
		}
		tmp = fabs(sum[i] - tmax);
		if (tmp > tans){
			tans = tmp;
			if (sum[i] - tmax < 0){ neg = true; }
			else neg = false;
		}
		tmin = min(tmin, sum[i]);
		tmax = max(tmax, sum[i]);
	}
	if (neg){ for (int i = 1; i <= n; i++) a[i] = -a[i]; }
	double l = 0.0, r = tans, ans = tans, mid, midmid, tmid, tmidmid;
	for (int i = 0; i < 300; i++){
		mid = (l + r) / 2;
		midmid = (mid + r) / 2;
		tmid = cal(mid);
		tmidmid = cal(midmid);
		if (tmid <= tmidmid){
			r = midmid;
			if (tmid < ans) ans = tmid;
		}
		else{
			l = mid;
			if (tmidmid < ans) ans = tmidmid;
		}
	}
	printf("%.10f\n", ans);
	return 0;
}

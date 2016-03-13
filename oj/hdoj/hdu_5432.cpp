/*************************************************************************
    > File Name: a.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sat Sep 12 19:15:02 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-5;
int T, n;
int a[11000], b[11000];
int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		int mx = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			mx = max(a[i], mx);
		}
		for (int i = 0; i < n; i++) scanf("%d", &b[i]);
		long long tot = 0; // /3
		for (int i = 0; i < n; i++) tot += (long long)b[i] * b[i] * a[i];
		double l = 0.0, r = mx, need = (double)tot/6;
		while(fabs(r - l) >= eps){
			double mid = (l + r) / 2.0;
			double sum = 0;
			for (int i = 0; i < n; i++){
				if (mid < a[i]){
					double h = (double)a[i] - mid;
					double w = b[i] * h / a[i];
					sum += h * w * w / 3;
				}
			}
			if (fabs(sum - need) < eps){ l = mid; break; }
			if (sum < need) r = mid;
			else l = mid;
		}
		printf("%d\n", (int)l);
	}
	return 0;
}

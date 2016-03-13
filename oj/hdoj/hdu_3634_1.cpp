/*************************************************************************
    > File Name: hdu_3634.cpp
    > Author: james47
    > Mail: 
    > Created Time: Mon Aug 10 13:04:07 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

struct rec{
	int x1, y1, x2, y2, val;
	friend bool operator < (const rec& a, const rec& b){
		return a.val > b.val;
	}
} r[30];
int x[60], y[60];
bool mp[60][60];
int T, n, cas = 0;
int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		map<int, int> mx, my;
		int cnt = 0;
		for (int i = 0; i < n; i ++){
			scanf("%d %d %d %d %d", &r[i].x1, &r[i].y1, &r[i].x2, &r[i].y2, &r[i].val);
			mx[r[i].x1] = -1; mx[r[i].x2] = -1;
			my[r[i].y1] = -1; my[r[i].y2] = -1;
		}
		int xsize = 0, ysize = 0;
		for (map<int, int>::iterator it = mx.begin(); it != mx.end(); it++){
			x[xsize] = it->first;
			it->second = xsize++;
		}
		for (map<int, int>::iterator it = my.begin(); it != my.end(); it++){
			y[ysize] = it->first;
			it->second = ysize++;
		}
		sort(r, r+n);
		for (int i = 0; i < xsize; i++)
			for (int j = 0; j < ysize; j++) mp[i][j] = false;
		long long ans = 0;
		for (int id = 0; id < n; id++){
			int a = mx[r[id].x1], b = mx[r[id].x2], c = my[r[id].y1], d = my[r[id].y2];
			for (int i = a; i < b; i++)
				for (int j = c; j < d; j++)
					if (!mp[i][j]){
						mp[i][j] = true;
						ans += (long long)r[id].val * (x[i+1] - x[i]) * (y[j+1] - y[j]);
					}
		}
		printf("Case %d: %lld\n", ++cas, ans);
	}
	return 0;
}

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
using namespace std;

struct rec{
	int x1, y1, x2, y2, val;
	bool operator <(const rec& that) const{
		return val > that.val;
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
		int cnt = 0;
		for (int i = 0; i < n; i ++){
			scanf("%d %d %d %d %d", &r[i].x1, &r[i].y1, &r[i].x2, &r[i].y2, &r[i].val);
			x[cnt] = r[i].x1; y[cnt++] = r[i].y1;
			x[cnt] = r[i].x2; y[cnt++] = r[i].y2;
		}
		sort(x, x+cnt); sort(y, y+cnt);
		int xsize = unique(x, x+cnt) - x,
			ysize = unique(y, y+cnt) - y;
		sort(r, r+n);
		for (int i = 0; i < xsize; i++)
			for (int j = 0; j < ysize; j++) mp[i][j] = false;
		long long ans = 0;
		for (int id = 0; id < n; id++){
			int a = lower_bound(x, x+xsize, r[id].x1) - x,
				b = lower_bound(x, x+xsize, r[id].x2) - x,
				c = lower_bound(y, y+ysize, r[id].y1) - y,
				d = lower_bound(y, y+ysize, r[id].y2) - y;
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

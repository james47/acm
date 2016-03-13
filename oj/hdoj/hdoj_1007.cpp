#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#define debug 0
const int max_n = 1e5;
const double eps = 1e-6;
const double inf = 1e20;
struct point{
	double x, y;
} p[max_n+10], tp[max_n+10], tmp[max_n+10];
bool cmp(point a, point b){
	return a.x < b.x;
}
#define dist(a, b) sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))

double solve(point p[], int l, int r){
	if (l == r) return inf;
	int m = l + r >> 1;
	double ret = min(solve(p, l, m), solve(p, m+1, r));
	int id, pl = l, pr = m+1, pc = l, cnt = 0;
	while(pl <= m && pr <= r){
		if (p[pl].y < p[pr].y){
			tp[pc++] = p[pl];
			if (p[m].x - p[pl].x <= ret)
			//if (dist(p[m], p[pl]) - ret < -eps)
				tmp[cnt++] = p[pl];
			pl++;
		}
		else{
			tp[pc++] = p[pr];
			if (p[pr].x - p[m].x <= ret)
			//if (dist(p[m], p[pr]) - ret < -eps)
				tmp[cnt++] = p[pr];
			pr++;
		}
	}
	while(pl <= m){
		tp[pc++] = p[pl];
		if (p[m].x - p[pl].x <= ret)
	//	if (dist(p[m], p[pl]) - ret < -eps)
			tmp[cnt++] = p[pl];
		pl++;
	}
	while(pr <= r){
		tp[pc++] = p[pr];
		if (p[pr].x - p[m].x <= ret)
	//	if (dist(p[m], p[pr]) - ret < -eps)
			tmp[cnt++] = p[pr];
		pr++;
	}

	if (debug) for (int i = 0; i < cnt; i++) printf("%.2lf, %.2lf\n", tmp[i].x, tmp[i].y);

	memcpy(p+l, tp+l, sizeof(p[0])*(r-l+1));
	//for (int i = l; i <= r; i++) p[i] = tp[i];
	double val;
	for (int i = 0; i < cnt; i++)
		for (int j = i+1; j < i+7 && j < cnt; j++){
			val = dist(tmp[i], tmp[j]);
			if (val < ret) ret = val;
		}
	return ret;
}

int n;
int main()
{
	while(scanf("%d", &n) && n){
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &p[i].x, &p[i].y);
		sort(p, p+n, cmp);
		double ans = solve(p, 0, n-1);
		printf("%.2lf\n", ans/2);
	}
	return 0;
}

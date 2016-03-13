#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<ctime>
#include<string>
using namespace std;

const double eps = 1e-8;
inline int sign(double a){
	return a < -eps ? -1 : a > eps;
}
struct point{
	double x, y;
	point (){}
	point (double _x, double _y) : x(_x), y(_y){}
	point operator +(const point &p) const{
		return point(x + p.x, y + p.y);
	}
	point operator -(const point &p) const{
		return point(x - p.x, y - p.y);
	}
	point operator *(double d) const{
		return point(x * d, y * d);
	}
	point operator /(double d) const{
		return point(x / d, y / d);
	}
	double dot(const point&p) const{
		return x * p.x + y * p.y;
	}
} s[200];
struct seg{
	point x, y;
} a[110];

#define cross(p1, p2, p3) ((p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y))
#define crossOp(p1, p2, p3) sign(cross(p1, p2, p3))

point isSS(point p1, point p2, point q1, point q2)
{
	double a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
	return (p1 * a2 + p2 * a1) / (a1 + a2);
}
int onSegment(point p, point q1, point q2)
{
	return crossOp(q1, q2, p) == 0 && sign((p - q1).dot(p - q2)) <= 0;
}
int isIntersect(point p1, point p2, point q1, point q2)
{
	return crossOp(p1, p2, q1) * crossOp(p1, p2, q2) < 0 && crossOp(q1, q2, p1) * crossOp(q1, q2, p2) < 0;
}
bool meet(point p1, point p2, point q1, point q2)
{
	if (isIntersect(p1, p2, q1, q2)) return true;
	if (onSegment(p1, q1, q2) || onSegment(p2, q1, q2) || onSegment(q1, p1, p2) || onSegment(q2, p1, p2)) return true;
	return false;
}
double dis(point a, point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool cmp(point a, point b)
{
	if (fabs(a.x - b.x) < eps) return a.y < b.y;
	return a.x < b.x;
}
int n, x, y, xx, yy;
int main()
{
	int cas = 0;
	while(scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++){
			scanf("%d %d %d %d", &x, &y, &xx, &yy);
			point tmp;
			tmp.x = x; tmp.y = y;
			a[i].x = tmp;
			tmp.x = xx; tmp.y = yy;
			a[i].y = tmp;
		}
		int cnt, ans = 0;
		for (int i = 0; i < n; i++){
			cnt = 0;
			s[cnt++] = a[i].x;
			s[cnt++] = a[i].y;
			for (int j = 0; j < n; j++){
				if (i != j){
					if (meet(a[i].x, a[i].y, a[j].x, a[j].y)){
						point tmp = isSS(a[i].x, a[i].y, a[j].x, a[j].y);
						s[cnt++] = tmp;
					}
				}
			}
			sort(s, s+cnt, cmp);
	//		printf("%d\n", cnt);
	//		for (int j = 0; j < cnt; j++)
	//			printf("%.4f %.4f\n", s[j].x, s[j].y);
			if (cnt == 2){
				ans += int(dis(a[i].x, a[i].y)/50.0) + 1; 
			}
			else{
				double tmp = (dis(s[0], s[1]) - 25.0)/50.0;
				//printf("%.4f\n", tmp);

				if (tmp > -eps) ans += int(tmp) + 1;
				tmp = (dis(s[cnt-1], s[cnt-2]) - 25.0)/50.0;
				//printf("%.4f\n", tmp);

				if (tmp > -eps) ans += int(tmp) + 1;
				for (int j = 1; j < cnt-2; j++){
					tmp = (dis(s[j], s[j+1]) - 50.0)/50.0;
					//printf("%.4f\n", tmp);
					if (tmp > -eps) ans += int(tmp) + 1;
				}
			}
		}
		printf("Map %d\n", ++cas);
		printf("Trees = %d\n", ans);
	}
	return 0;
}


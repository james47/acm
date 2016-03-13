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

const double pi = acos(-1.0);
int n;
double d;
const double eps = 1e-8;
inline int sign(double a){
    return a < -eps ? -1 : a > eps;
}
#define cross(p1, p2, p3) ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y))
#define crossOp(p1, p2, p3) sign(cross(p1, p2, p3))
struct point{
    double x, y, id;
    point(){}
    point(double _x, double _y): x(_x), y(_y){}
    bool operator < (const point &p) const{
        int c = sign(x - p.x);
        if (c) return c == -1;
        return sign(y - p.y) == -1;
    }
    point operator -(const point &p) const{
        return point(x - p.x, y - p.y);
    }
    double dot(const point &p) const{
        return x * p.x + y * p.y;
    }
};

double dis(point a, point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y -b.y)*(a.y-b.y));
}
int onSegment(point p, point q1, point q2)
{
    return crossOp(q1, q2, p) == 0 && sign((p-q1).dot(p-q2)) <= 0;
}
vector<point> convexHull(vector<point> ps)
{
    int n = ps.size();
    if (n <= 1)
        return ps;
    sort(ps.begin(), ps.end());
    vector<point> qs;
    for (int i = 0; i < n; qs.push_back(ps[i++])){
        while(qs.size() > 1 && crossOp(qs[qs.size()-2], qs.back(), ps[i]) <= 0)
            qs.pop_back();
    }
    for (int i = n - 2, t = qs.size(); i >= 0; qs.push_back(ps[i--])){
        while((int)qs.size() > t && crossOp(qs[(int)qs.size()-2], qs.back(), ps[i]) <= 0)
            qs.pop_back();
    }
    qs.pop_back();
    return qs;
}

vector<point> p, ans;
int T;
int main()
{
	scanf("%d", &T);
	int cas = 0;
	while(T--)
	{
		p.clear();
		scanf("%d %lf", &n, &d);
		double x, y;
		for (int i = 0; i < n; i++){
			scanf("%lf %lf", &x ,&y);
			p.push_back(point(x, y));
		}
		ans = convexHull(p);
		double C = 0;
		int size = ans.size();
		for (int i = 0; i < size; i++){
			C += dis(ans[i], ans[(i+1)%size]);
		}
		printf("Case #%d: %.4lf\n", ++cas, C/pi/d);
	}
	return 0;
}


#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;
inline int sign(double a){
	return a < -eps ? -1: a > eps;
}
struct point{
	double x, y;
	point(){}
	point(double _x, double _y): x(_x), y(_y) {}
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
	point rot90() const{
		return point(-y, x);
	}
	point unit(){
		return *this / abs();
	}
	double distTo(const point &p) const{
		double dx = x - p.x, dy = y - p.y;
		return hypot(dy, dx);
	}
	double abs(){
		return hypot(x, y);
	}
	double abs2(){
		return x * x + y * y;
	}
};

#define cross(p1, p2, p3) ((p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y-p1.y))
#define crossOp(p1, p2, p3) sign(cross(p1, p2, p3))

point isSS(point p1, point p2, point q1, point q2)
{
	double a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
	return (p1 * a2 + p2 * a1) / (a1 + a2);
}
struct circle{
	point c;
	double r;
	circle(){}
	circle(point _c, double _r): c(_c), r(_r){}
};


int isIntersectCircleToCircle(point c1, double r1, point c2, double r2)
{
	double dis = c1.distTo(c2);
	return sign(dis - abs(r1 - r2)) >= 0 && sign(dis - (r1 + r2)) <= 0;
}
void intersectionLineToCircle(point c, double r, point l1, point l2, point &p1, point &p2)
{
	point c2 = c + (l2 - l1).rot90();
	c2 = isSS(c, c2, l1, l2);
	double t = sqrt(r * r - (c2 - c).abs2());
	p1 = c2 + (l2 - l1).unit() * t;
	p2 = c2 - (l2 - l1).unit() * t;
}
void intersectionCircleToCircle(point c1, double r1, point c2, double r2, point &p1, point &p2)
{
	double t = (1 + (r1 * r1 - r2 * r2) / (c1 - c2).abs2()) / 2;
	point u = c1 + (c2 - c1) * t;
	point v = u + (c2 - c1).rot90();
	intersectionLineToCircle(c1, r1, u, v, p1, p2);
}
vector<circle> c;
vector<point> p;
int n;
double x, y, r;
int cal(int id)
{
	int ret = 0;
	point pp = p[id];
	for (int i = 0; i < n; i++)
		if (pp.distTo(c[i].c) - c[i].r < eps) ret++;
	return ret;
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		c.clear();
		for (int i = 0; i < n; i++){
			scanf("%lf %lf %lf", &x, &y, &r);
			c.push_back(circle(point(x, y), r));
		}
		p.clear();
		for (int i = 0; i < n; i++) p.push_back(c[i].c);
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				if (isIntersectCircleToCircle(c[i].c, c[i].r, c[j].c, c[j].r)){
					point t1, t2;
					intersectionCircleToCircle(c[i].c, c[i].r, c[j].c, c[j].r, t1, t2);
					p.push_back(t1);
					p.push_back(t2);
				}
		int ans = 0;
		for (int i = 0; i < p.size(); i++){
			ans = max(ans, cal(i));
		}
		printf("%d\n", ans);
	}
	return 0;
}

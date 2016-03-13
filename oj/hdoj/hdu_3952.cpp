#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;

const double EPS = 1e-8;
inline int sign(double a){
	return a < -EPS? -1: a > EPS;
}

struct Point{
	double x, y;
	Point(){}
	Point(double _x, double _y): x(_x), y(_y){}
	Point operator+(const Point&p) const{
		return Point(x + p.x, y + p.y);
	}
	Point operator-(const Point&p) const{
		return Point(x - p.x, y - p.y);
	}
	Point operator*(double d) const{
		return Point(x * d, y * d);
	}
	Point operator/(double d) const{
		return Point(x / d, y / d);
	}
	double dot(const Point&p) const{
		return x * p.x + y * p.y;
	}
	void write(){
		cout << '(' << x << ',' << y << ')' << endl;
	}
} p[30][30];
int ct[30]; 

#define cross(p1, p2, p3) ((p2.x - p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1, p2, p3) sign(cross(p1, p2, p3))

Point isSS(Point p1, Point p2, Point q1, Point q2){
	double a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
	//puts("");
	//cout << a1 << ' ' << a2 << endl;
	//printf("%.4f %.4f\n");
	//puts("");
	return (p1 * a2 + p2 * a1) / (a1 + a2);
}

int onSegment(Point p, Point q1, Point q2){
	return crossOp(q1, q2, p) == 0 && sign((p - q1).dot(p - q2)) <= 0;
}

int T, n, k;
int main()
{
	scanf("%d", &T);
	int cas = 0;
	//Point p1 = Point(-1, 1), p2 = Point(2, 1), p3 = Point(-1, 0), p4 = Point(2, 0);
	//isSS(p1, p2, p3, p4).write();
	while(T--){
		scanf("%d", &n);
		int x, y;
		for (int i = 0; i < n; i++){
			scanf("%d", &ct[i]);
			for (int j = 0; j < ct[i]; j++){
				scanf("%d %d", &x, &y);
				p[i][j] = Point((double)x, (double)y);
			}
		}
		int ans = 1;
		for (int i = 0; i < n; i++){
			for (int j = i+1; j < n; j++){
				for (int k = 0; k < ct[i]; k++){
					for (int l = 0; l < ct[j]; l++){
						Point p1 = p[i][k], p2 = p[j][l], p3, p4;
						int tmp = 2;
						for (int cc = 0; cc < n; cc++) if (cc != i && cc != j){
							for (int cp = 0; cp < ct[cc]; cp++){
								p3 = p[cc][cp], p4 = p[cc][(cp+1)%ct[cc]];
								int dx = p1.x - p2.x, dx1 = p3.x - p4.x;
								int dy = p1.y - p2.y, dy1 = p3.y - p4.y;
								if (dx == 0 && dx1 == 0) continue;
								//if (fabs((double)dy/(double)dx - (double)dy1/(double)dx1) < EPS) continue;
								if (dx * dy1 == dy * dx1) continue;
								if (onSegment(isSS(p1, p2, p3, p4), p3, p4)){
									tmp++;
									//puts("");
									//p1.write(), p2.write(), p3.write(), p4.write();
									//isSS(p1, p2, p3, p4).write();
									//puts("");
									break;
								}
							}
						}
						ans = max(tmp, ans);
					}
				}
			}
		}
		printf("Case %d: %d\n", ++ cas, ans);
	}
	return 0;
}

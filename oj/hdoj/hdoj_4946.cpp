#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

const double eps = 1e-8;
inline int sign(double a){
    return a < -eps ? -1 : a > eps;
}
#define cross(p1, p2, p3) ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y))
#define crossOp(p1, p2, p3) sign(cross(p1, p2, p3))
struct stu{
    int x, y, v, id;
} s[1000];
struct point{
    int x, y, id;
    point(){}
    point(int _x, int _y): x(_x), y(_y){}
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
int n, cas = 0;
bool uni[1000];
char ans[1000];

int onSegment(point p, point q1, point q2)
{
    return crossOp(q1, q2, p) == 0 && sign((p-q1).dot(p-q2)) <= 0;
}
vector<point> p, ans1;
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

void output()
{
    printf("Case #%d: %s\n", ++cas, ans);
    return ;
}
int main()
{
    while(scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i ++) ans[i] = '0';
        ans[n] = '\0';
        int maxv = -1;
        for (int i = 0; i < n; i++){
            scanf("%d %d %d", &s[i].x, &s[i].y, &s[i].v);
            s[i].id = i;
            maxv = max(maxv, s[i].v);
        }
        if (maxv == 0){
            output();
            continue;
        }
        memset(uni, true, sizeof(uni));
        for (int i = 0; i < n; i++){
            if (uni[i])
                for (int j = i+1; j < n; j++){
                    if (s[i].x == s[j].x && s[i].y == s[j].y && s[i].v == s[j].v)
                        uni[i] = uni[j] = false;
                }
        }
  //      for (int i = 0; i < n; i++)
  //          if (uni[i]) printf("%d\n", i);
        p.clear();
        for (int i = 0; i < n; i++){
            if (s[i].v == maxv){
                point tmp;
                tmp.x = s[i].x;
                tmp.y = s[i].y;
                tmp.id = s[i].id;
                p.push_back(tmp);
            }
        }
       // for (int i = 0; i < p.size(); i++)
       //     printf("%d %d %d\n", p[i].x, p[i].y, p[i].id);
        ans1 = convexHull(p);
//        for (int i = 0; i < ans1.size(); i++)
//            printf("%d %d %d\n", ans1[i].x, ans1[i].y, ans1[i].id);
        for (int i = 0; i < ans1.size(); i++)
            if (uni[ans1[i].id]) ans[ans1[i].id] = '1';
        for (int i = 0; i < n; i++)
            if (ans[i] == '0' && s[i].v == maxv && uni[i]){
                point now;
                now.x = s[i].x;
                now.y = s[i].y;
                now.id = i;
                for (int j = 0; j < ans1.size()-1; j++)
                    if (onSegment(now, ans1[j], ans1[j+1])){
                        ans[i] = '1';
                        break;
                    }
		if (onSegment(now, ans1[0], ans1[ans1.size()-1])){
			ans[i] = '1';
		}
            }
        output();
    }
    return 0;
}

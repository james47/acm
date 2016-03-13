#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const double eps = 1e-6;
int T;
double d, r, T1, T2, T3, v1, v2;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf", &d, &r, &T1, &T2, &T3, &v1, &v2);
		if (T1 > T2 + eps){
			puts("no");
			continue;
		}
		if (v1 - v2 > -eps){
			//if (d <= r)
			if (d - r < eps){
				puts("yes");
				continue;
			}
			else{
				double deltad = d - r;
				double dsan = (v1 - 0.5 * v2) * T3;
				if (eps + dsan < deltad){
					if (fabs(v1 - v2) < eps){
						puts("no");
						continue;
					}
					deltad -= dsan;
					double tt = T3 + deltad / (v1 - v2);
					double T = T2 - tt;
					if (T - T1 > -eps) puts("yes");
					else puts("no");
					continue;
				}
				else{
					double T = T2 - (deltad/(v1 - 0.5 * v2));
					if (T - T1 > -eps) puts("yes");
					else puts("no");
					continue;
				}
			}
		}
		else{
			//if (d <= r)
			if (d - r < eps){
				double deltad = r - d;
				if (v1 - 0.5 * v2 < eps){ // v1 <= 0.5v2 type A
					double dsan = (0.5 * v2 - v1) * T3;
					if (dsan - deltad > -eps){
						double T = deltad / (0.5 * v2 - v1);
						if (T - T2 > eps)
							T = T2;
						if (T - T1 > -eps) puts("yes");
						else puts("no");
						continue;
					}
					else{
						deltad = deltad - dsan;
						double tt2 = deltad / (v2 - v1);
						double T;
						if (tt2 + T3 > T2 + eps){
							T = T2;
						}
						else T = tt2 + T3;
						if (T - T1 > -eps) puts("yes");
						else puts("no");
						continue;
					}
				}
				else{ //v1 > 0.5v2 type B
					double tt1 = deltad / (v2 - v1);
					double dsan = (v1 - 0.5 * v2) * T3;
					if (dsan - r > eps) dsan = r;
					double tt2 = dsan / (v2 - v1);
					double T = tt1 + tt2 + T3;
					if (T - T1 > -eps) puts("yes");
					else puts("no");
				}
			}
			else{//d > r
				if (v1 - 0.5 * v2 < eps){//if (v1 <= 0.5 * v2)
					puts("no");
					continue;
				}
				else{//type C;
					double deltad = d - r;
					double dsan = (v1 - 0.5 * v2) * T3;
					if (dsan - deltad < eps){
						puts("no");
						continue;
					}
					else{
						double tneed = deltad / (v1 - 0.5 * v2);
						double newdelta;
						if (dsan - d > -eps){
							newdelta = 0;
						}
						else newdelta = d - dsan;
						double tt2 = (r - newdelta)/(v2 - v1);
						if (tneed > T2 + eps){
							puts("no");
							continue;
						}
						double T = T3 - tneed + tt2;
						if (T > T2 - tneed + eps) T = T2 - tneed;
						if (T - T1 > -eps) puts("yes");
						else puts("no");
					}
				}
			}
		}
	}
	return 0;
}

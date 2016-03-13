#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
		double w, h, d, p;
		while(scanf("%lf %lf %lf %lf", &w, &h, &d, &p) && (w + h + d + p))
		{
				double ave = w * h * 2.0 / p;
				int cnt = 0;
				double x = w, y = 0, r = w - d;
				while (cnt < p - 1)
				{
                                        if (abs(x - w) < 1e-4)
                                        {
                                                if ((h - y) * r >= ave)
                                                {
                                                        y = y + ave / r;
                                                }
                                                else
                                                {
                                                        double res = (h - y) * r;
                                                        x = w - (ave - res) / h;
                                                        y = h;
                                                }
                                        }
                                        else if (abs(y - h) < 1e-4)
                                        {
                                                if (x * h >= ave)
                                                        x = x - ave / h;
                                                else
                                                {
                                                        double res = x * h;
                                                        x = 0;
                                                        y = h - (ave - res) / d;
                                                }
                                        }
                                        else
                                        {
                                                y = y - ave / d;
                                        }
                                        cnt++;
                                        printf("%.3lf %.3lf", x, y);
                                        if (cnt < p - 1) printf(" ");
				}
				printf("\n");
		}
		return 0;
}

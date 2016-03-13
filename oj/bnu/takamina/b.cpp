#include<cstdio>
#include<cstring>
using namespace std;

char s1[200], s2[200];
double c(int m, int n){
	int ret = 1;
	if (m == 0 || m == n) return (double)ret;
	for (int i = n, j = 1; j <= m; i--, j++)
		ret = ret * i / j;
	return (double)ret;
}
int main()
{
	while(scanf("%s", s1) != EOF){
		scanf("%s", s2);
		int p1 = 0, p2 = 0, num = 0, len = strlen(s1);
		for (int i = 0; i < len; i++){
			if (s1[i] == '+') p1 ++;
			else p1--;
			if (s2[i] == '+') p2 ++;
			else if (s2[i] == '-') p2 --;
			else num++;
		}
		int need = p1 - p2;
		if (need < 0) need *= -1;
		double ans = 0.0;
		if (need <= num && ((num-need)%2==0)){
			int k = (num - need) / 2 + need;
			if (k > num / 2) k = num - k;
			ans = c(k, num);
			for (int i = 0; i < num; i++) ans /= 2.0;
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}

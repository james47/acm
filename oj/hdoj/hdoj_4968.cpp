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

int T, ave, n;
double gpa[] = {2.0, 2.5, 3.0, 3.5, 4.0};
int ct[10];
double cal(int ct[])
{
	//for (int i = 0; i < 5; i++)
	//	printf("%d\n", ct[i]);
	double ret = 0;
	for (int i = 0; i < 5; i++)
		ret = ret + gpa[i] * (double)ct[i];
	return ret / n;
}
double calmin(int ave, int tot, int n)
{
	if (ave <= 9) return 2.0000;
	tot -= 9 * n;
	memset(ct, 0, sizeof(ct));
	ct[0] = n;
	while(tot){
		ct[0]--;
		if (tot >= 31){
			tot -= 31;
			ct[4] ++;
		}
		else{
			if (tot >= 16) ct[4] ++; 
			else if (tot >= 11) ct[3] ++;
			else if (tot >= 6) ct[2] ++;
			else ct[1] ++;
			tot = 0;
		}
	}
	return cal(ct);
}
double calmax(int ave, int tot, int n)
{
	if (ave >= 25) return 4.0000;
	memset(ct, 0, sizeof(ct));
	ct[0] = n;
	while(tot){
		if (tot > 9) ct[0] --;
		else {tot = 0; continue;}
		if (tot < 25){
			if (tot >= 20) ct[3] ++;
			else if (tot >= 15) ct[2] ++;
			else ct[1] ++;
			tot = 0;
		}
		else {tot -= 25; ct[4] ++;}
	}
	return cal(ct);
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &ave, &n);
		ave -= 60;
		int tot = ave * n;
		double ansmin, ansmax;
		ansmin = calmin(ave, tot, n);
		ansmax = calmax(ave, tot, n);
		printf("%.4f %.4f\n", ansmin, ansmax);
	}
	return 0;
}


#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
struct node{
	int ct, p;
} b[5010];
int n;
int v[5010], a[5010], dp[5010];
bool cmp(node a, node b)
{
	return a.p < b.p;
}
int main()
{
	while(scanf("%d", &n) && n)
	{
		for (int i = 1; i <= n; i++) scanf("%d", v+i);
		for (int i = 1; i <= n; i++) scanf("%d", a+i);
		int p1 = 0, p2 = n+1, ct1 = 0, ct2 = 0, num = 0, pos1 = 1, pos2 = n;
		LL sum1 = 0, sum2 = 0;
		while(p1 + 1 < p2)
		{
			if (sum2 < sum1) sum2 = sum2 + v[--p2], ct2 ++;
			else sum1 = sum1 + v[++p1], ct1 ++;
			if (sum1 == sum2){
				b[++num].ct = ct1;
				b[num].p = pos1 ++;
				b[++num].ct = ct2;
				b[num].p = pos2 --;
				sum1 = sum2 = 0;
				ct1 = ct2 = 0;
			}
		}
		//if (sum1 != sum2){
		if (ct1 || ct2){
			b[++num].ct = ct1 + ct2;
			b[num].p = pos1 ++;
		}
		sort(b+1, b+1+num, cmp);
	//	for (int i = 1; i <= num; i++)
	//		printf("%d %d\n", b[i].ct, b[i].p);
		dp[0] = 0;
		for (int i = 1; i * 2 <= num; i++){
			int sum1 = 0, sum2 = 0;
			for (int j = i; j > 0; j--){
				sum1 += b[j].ct; sum2 += b[num-j+1].ct;
				if (j == i) dp[i] = dp[i-1] + a[sum1] + a[sum2];
				else dp[i] = min(dp[i], dp[j-1] + a[sum1] + a[sum2]);
			}
		}
		int ans = a[n], sum = 0;
		for (int i = 1; i <= num/2; i++){
			sum += b[i].ct + b[num-i+1].ct;
			ans = min(ans, dp[i] + a[n-sum]);
		}
		printf("%d\n", ans);
	}
	return 0;
}

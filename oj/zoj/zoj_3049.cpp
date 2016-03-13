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

int ans, n, p, sum1, sum2, sum3, num, inf;
int a[1100], b[1100], dp[1100];
char str[300];
int read(int &p)
{
	int ans = 0, len = strlen(str);
	while(p < len && (str[p] < '0' || str[p] > '9')) p++;
	//if (p == len) return -1;
	while(p < len && (str[p] >= '0' && str[p] <= '9')){
		ans = ans * 10 + str[p] - '0';
		p++;
	}
	return ans;
}
void init()
{
	sum1 = sum2 = sum3 = num = 0;
	int p1, p2;
	gets(str);
	for (int i = 0; i < n; i++){
		gets(str);
		int pos = 0;
		p1 = read(pos);
		pos++;
		p2 = read(pos);
		if (p2 == 0 || p2 - p1 <= p){
			sum1 += p1;
			sum3 += p1;
		}
		else{
			sum1 += p1;
			a[num] = p1;
			b[num] = p2 - p1 - p;
			sum2 += b[num];
			num++;
		}
	}
}
void solve()
{
	memset(dp, 127, sizeof(dp));
	inf = dp[0];
	dp[0] = 0;
	for (int i = 0; i < num; i++){
		for (int j = p; j >= 0; j--){
			if (dp[j] == inf) continue;
			int to = j + a[i];
			if (to > p) to = p;
			if (dp[j] + b[i] < dp[to]) dp[to] = dp[j] + b[i];
		}
		/*
		if (a[i] > p){
			if (dp[p] > b[i]) dp[p] = b[i];
		}
		else{
			if (dp[p-a[i]] != inf){
				int tmp = dp[p-a[i]] + b[i];
				if (tmp < dp[p]){
					dp[p] = tmp;
				}
			}
		}
		for (int j = p-1; j >= a[i]; j--){
			int id = j - a[i];
			if (dp[id] != inf){
				int tmp = dp[id] + b[i];
				if (tmp < dp[j]){
					dp[j] = tmp;
				}
			}
		}
		*/
	}
}
int main()
{
	while(scanf("%d %d", &n, &p) != EOF)
	{
		init();
		if (sum3 >= p){
			int ans = sum1 + sum2;
			printf("%d\n", ans);
		}
		else{
			if (sum1 < p){
				int ans = sum1;
				printf("%d\n", ans);
			}
			else{
				p = p - sum3;
				solve();
				ans = sum1 + sum2 - dp[p];
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}

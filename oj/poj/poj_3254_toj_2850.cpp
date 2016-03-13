/*************************************************************************
    > File Name: toj_2850.cpp
    > Author: james47
    > Mail: 
    > Created Time: Mon Aug  3 15:58:12 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int mod = (int)1e8;
int st[5000], ct[5000];
int dp[15][5000];
int a[15];
int size = 0;
int n, m;
void init(){
	int tmp;
	for (int i = 0; i < (1<<m); i++)
		if ((i&(i<<1)) == 0){
			st[size] = i;
			ct[size] = 0;
			tmp = i;
			while(tmp){
				tmp &= tmp-1;
				ct[size]++;
			}
			size++;
		}
}
int main()
{
	scanf("%d %d", &n, &m);
	init();
	int y, x;
	for (int i = 0; i < n; i++){
		y = 0;
		for (int j = 0; j < m; j++){
			scanf("%d", &x);
			if (!x) y |= 1<<j;
		}
		a[i] = y;
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < size; j++){
			if (a[i] & st[j]) continue;
			if (i == 0) dp[0][j] = 1;
			else
				for (int k = 0; k < size; k++){
					if (!(a[i-1]&st[k]) && !(st[j]&st[k])){
						dp[i][j] += dp[i-1][k];
						if (dp[i][j] > mod) dp[i][j] -= mod;
					}
				}
		}
	}
	int ans = 0;
	for (int i = 0; i < size; i++){
		ans += dp[n-1][i];
		if (ans > mod) ans -= mod;
	}
	printf("%d\n", ans);
	return 0;
}

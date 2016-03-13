/*************************************************************************
  > File Name: toj_4124.cpp
  > Author: james47
  > Mail: 
  > Created Time: Thu Jun 11 01:05:35 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

unsigned int dp[201][201][110];
void work(){
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < 200; i++)
		dp[i][i][0] = dp[i][i+1][1] = dp[i+1][i][1] = 1;
	for (int k = 2; k <= 100; k++){
		for (int i = 0; i <= 200; i++)
			for (int j = 0; j <= 200; j++){
				if (j < 200) dp[i][j][k] += dp[i][j+1][k-1];
				if (j > 0) dp[i][j][k] += dp[i][j-1][k-1];
			}
	}

}
int n, m, k;
int main()
{
	work();
	while(scanf("%d %d %d", &n, &m, &k) != EOF){
		printf("%u\n", dp[n][m][k]);
	}
	return 0;
}

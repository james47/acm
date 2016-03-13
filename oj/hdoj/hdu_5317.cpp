/*************************************************************************
    > File Name: hdu_5317.cpp
    > Author: james47
    > Mail: 
    > Created Time: Wed Jul 29 08:59:09 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = (int)1e6+1;
int T, l, r, size;
int f[maxn];
int s[maxn][11];
int mpf[maxn];
int prime[maxn];
int ans[11];
void init(){
	memset(mpf, 0, sizeof(mpf));
	size = 0;
	for (int i = 2; i * i < maxn; i++){
		if (mpf[i] == 0) prime[size++] = i;
		for (int j = 0; j < size && i * prime[j] < maxn && (prime[j] <= mpf[i] || mpf[i] == 0); j++)
			mpf[i*prime[j]] = prime[j];
	}
	f[1] = 0;
	for (int i = 0; i <= 8; i++) s[0][i] = s[1][i] = 0;
	s[1][0] = 1;
	int tmp;
	for (int i = 2; i <= maxn; i++){
		f[i] = 0;
		tmp = i;
		for (int j = 0; j < size; j++){
			if (tmp % prime[j] == 0){
				f[i] ++;
				tmp /= prime[j];
				while(tmp % prime[j] == 0) tmp /= prime[j];
			}
		}
		if (tmp != 1) f[i] ++;
		for (int j = 0; j <= 8; j++) s[i][j] = s[i-1][j];
		s[i][f[i]] ++;
	}
}
int main()
{
	scanf("%d", &T);
	init();
	while(T--){
		scanf("%d %d", &l, &r);
		for (int i = 0; i <= 8; i++){
			ans[i] = s[r][i] - s[l-1][i];
		}
		if (ans[8] >= 2) puts("8");
		else if (ans[7] >= 2) puts("7");
		else if (ans[6] >= 2) puts("6");
		else if (ans[5] >= 2) puts("5");
		else if (ans[8] + ans[4] >= 2) puts("4");
		else if (ans[6] + ans[3] >= 2) puts("3");
		else if (ans[8] + ans[6] + ans[4] + ans[2] >= 2) puts("2");
		else if (ans[1] >= 2) puts("1");
		else puts("0");
	}
	return 0;
}

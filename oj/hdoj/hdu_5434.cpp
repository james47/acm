/*************************************************************************
    > File Name: hdu_5434.cpp
    > Author: james47
    > Mail: 
    > Created Time: Mon Sep 14 23:00:50 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int mod = 1000000007;
const int MAXN = 130;
int N;
struct matrix{
	int a[MAXN][MAXN];
	friend matrix operator *(const matrix& a, const matrix& b){
		matrix ret;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) ret.a[i][j] = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++){
				for (int k = 0; k < N; k++){
					ret.a[i][k] = ((long long)a.a[i][j] * b.a[j][k] + ret.a[i][k]) % mod;
				}
			}
		return ret;
	}
	matrix pow(int exp){
		matrix ret, tmp = *this;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) ret.a[i][j] = i==j;
		for (; exp; exp >>= 1){
			if (exp&1) ret = ret * tmp;
			tmp = tmp * tmp;
		}
		return ret;
	}
} mat;

int n, m;
bool ok(int x, int y){
	for (int i = 0; i < m; i++){
		if (x&(1<<i)){
			if (i != 0){
				if ((y&(1<<i-1)) && !(y&(1<<i)) && !(x&(1<<i-1))) return 0;
			}
			if (i != m-1){
				if ((y&(1<<i+1)) && !(y&(1<<i)) && !(x&(1<<i+1))) return 0;
			}
		}
	}
	return 1;
}

int main()
{
	while(scanf("%d %d", &n, &m) != EOF){
		N = 1 << m;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++){
				if (ok(i, j)) mat.a[i][j] = 1;
				else mat.a[i][j] = 0;
			}
		mat = mat.pow(n);
		int ans = 0;
		for (int i = 0; i < N; i++){
			ans += mat.a[i][0];
			if (ans >= mod) ans -= mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}

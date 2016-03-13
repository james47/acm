/*************************************************************************
    > File Name: hdu_5318.cpp
    > Author: james47
    > Mail: 
    > Created Time: Wed Jul 29 10:13:14 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int mod = 1000000007;
struct mat{
	int m[55][55], l;
	void init(){
		for (int i = 0; i < l; i++)
			for (int j = 0; j < l; j++) m[i][j] = 0;
	}
	mat operator* (const mat& b) const{
		mat c; c.l = l; c.init();
		for (int i = 0; i < l; i++)
			for (int j = 0; j < l; j++)
				for (int k = 0; k < l; k++)
					c.m[i][j] = (c.m[i][j] + (long long)m[i][k] * b.m[k][j]) % mod;
		return c;
	}
	mat pow(int n){
		mat ret, x = *this; ret.l = l; ret.init();
		for (int i = 0; i < l; i++) ret.m[i][i] = 1;
		while(n){
			if (n&1) ret = ret * x;
			x = x * x;
			n >>= 1;
		}
		return ret;
	}
	void write(){
		for (int i = 0; i < l; i++){
			for (int j = 0; j < l; j++)
				printf("%d ", m[i][j]);
			puts("");
		}
	}
};

char a[55][20];
bool ok(int x, int y){
	int l0 = strlen(a[x]), l1 = strlen(a[y]), l = min(l0, l1);
	for (int i = 2; i <= l; i++){
		bool flag = true;
		for (int j = l0-i, k = 0; k < i; j++, k++)
			if (a[x][j] != a[y][k]){
				flag = false; break;
			}
		if (flag) return true;
	}
	return false;
}

bool cmp(char *a, char *b){
	if (strcmp(a, b) < 0) return true;
	return false;
}
int T, n, m;
int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%s", a[i]);
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				if (strcmp(a[i], a[j]) == 0) a[j][0] = 0;
		if (m == 0) {puts("1"); continue;}
		if (m == 1){
			printf("%d\n", n);
			continue;
		}
		mat f; f.l = n; f.init();
		for (int i = 0; i < n; i++)
			if (strlen(a[i]) > 1) f.m[i][i] = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (i != j && ok(j, i)) f.m[i][j] = 1;
		f = f.pow(m-1);
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) ans = (ans + f.m[i][j]) % mod;
		printf("%d\n", ans);
	}
	return 0;
}

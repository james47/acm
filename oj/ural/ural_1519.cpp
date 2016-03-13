/*************************************************************************
    > File Name: ural_1519.cpp
    > Author: james47
    > Mail: 
    > Created Time: Wed Jul 29 15:54:31 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define debug 0
typedef long long ll;
const int hash_size = 100007;
const int state_size = 1000000;
int n, m, lastx, lasty;

struct hashmap{
	int size;
	int head[hash_size];
	int nxt[state_size];
	ll state[state_size], num[state_size];
	void init(){
		size = 0;
		memset(head, -1, sizeof(head));
	}
	void push(ll st, ll val){
		int k = st % hash_size;
		for (int i = head[k]; i != -1; i = nxt[i])
			if (state[i] == st){
				num[i] += val;
				return;
			}
		state[size] = st;
		num[size] = val;
		nxt[size] = head[k];
		head[k] = size++;
	}
} dp[2];
int cur;

int cc[15];
ll code(int* a){
	memset(cc, 0, sizeof(cc));
	int cnt = 1;
	for (int i = 0; i <= m; i++) if (a[i]){
		if (!cc[a[i]]) cc[a[i]] = cnt++;
		a[i] = cc[a[i]];
	}
	ll ret = 0;
	for (int i = m; i >= 0; i--){
		ret <<= 3;
		ret = ret + a[i];
	}
	return ret;
}
void decode(ll x, int* a){
	for (int i = 0; i <= m; i++){
		a[i] = x & 7;
		x >>= 3;
	}
}
void shift(int* a){
	for (int i = m; i > 0; i--) a[i] = a[i-1];
	a[0] = 0;
}

int a[15];
char M[15][15];
void cal0(int x, int y){
	for (int i = 0; i < dp[cur].size; i++){
		decode(dp[cur].state[i], a);
		if (debug){
			printf("(%d,%d)\n", x, y);
			for (int i = 0; i <= m; i++) printf("%d ", a[i]);
			puts("");
		}
		ll num = dp[cur].num[i];
		int left = a[y-1], up = a[y];
		if (left && up){
			if (left == up){
				if (x == lastx && y == lasty){
					if (y == m) shift(a);
					dp[cur^1].push(code(a), num);
				}
			}
			else{
				for (int i = 0; i <= m; i++)
					if (a[i] == up) a[i] = left;
				a[y] = a[y-1] = 0;
				if (y == m) shift(a);
				dp[cur^1].push(code(a), num);
			}
		}
		else if (left || up){
			if (left){
				if (M[x+1][y] == '.'){
					a[y] = 0;
					if (y == m) shift(a);
					dp[cur^1].push(code(a), num);
				}
				if (M[x][y+1] == '.'){
					a[y-1] = 0; a[y] = left;
					dp[cur^1].push(code(a), num);
				}
			}
			else{
				if (M[x+1][y] == '.'){
					a[y-1] = up; a[y] = 0;
					if (y == m) shift(a);
					dp[cur^1].push(code(a), num);
				}
				if (M[x][y+1] == '.'){
					a[y-1] = 0; a[y] = up;
					dp[cur^1].push(code(a), num);
				}
			}
		}
		else{
			if (M[x+1][y] == '.' && M[x][y+1] == '.'){
				a[y-1] = a[y] = 13;
				if (y == m) shift(a);
				dp[cur^1].push(code(a), num);
			}
		}
	}
}
void cal1(int x, int y){
	for (int i = 0; i < dp[cur].size; i++){
		decode(dp[cur].state[i], a);

		if (debug){
			printf("(%d,%d)\n", x, y);
			for (int i = 0; i <= m; i++) printf("%d ", a[i]);
			puts("");
		}

		a[y] = a[y-1] = 0;
		if (y == m) shift(a);
		dp[cur^1].push(code(a), dp[cur].num[i]);
	}
}

ll solve(){
	cur = 0;
	dp[0].init();
	dp[cur].push(0, 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			dp[cur^1].init();
			if (M[i][j] == '.') cal0(i, j);
			else cal1(i, j);
			cur ^= 1;
		}
	ll ret = 0;
	for (int i = 0; i < dp[cur].size; i++)
		ret += dp[cur].num[i];
	return ret;
}

int main()
{
	while(scanf("%d %d", &n, &m) != EOF){
		memset(M, 0, sizeof(M));
		for (int i = 1; i <= n; i++) scanf("%s", M[i]+1);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (M[i][j] == '.') lastx = i, lasty = j;
		printf("%lld\n", solve());
	}
	return 0;
}

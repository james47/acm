/*************************************************************************
    > File Name: d.cpp
    > Author: james47
    > Mail: 
    > Created Time: Thu Sep 17 21:25:40 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ans;
int n, m;
char s[101000];
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> s;
	long long ans = n*m-n;
	for (int i = 1; i < n; i++){ if (s[i] != s[i-1]) ans += n*m - n; }
	long long len = 1;
	for (int i = 1; i < n; i++){
		if (len == 1){
			if (s[i] == s[i-1]) continue;
			else len = 2;
		}
		else{
			if (s[i] == s[i-2]) len ++;
			else{
				ans -= len * (len-1) / 2;
				if (s[i] == s[i-1]) len = 1;
				else len = 2;
			}
		}
	}
	ans -= len * (len-1) / 2;
	cout << ans << endl;
	return 0;
}

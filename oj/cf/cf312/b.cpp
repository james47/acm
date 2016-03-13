/*************************************************************************
    > File Name: b.cpp
    > Author: james47
    > Mail: 
    > Created Time: Wed Jul 15 13:13:02 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = (int)1e6+100;
int x, n;
int ct[maxn], ft[maxn], lt[maxn];
int main()
{
	scanf("%d", &n);
	memset(ct, 0, sizeof(ct));
	memset(ft, 0, sizeof(ft));
	memset(lt, 0, sizeof(lt));
	int num = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", &x);
		ct[x] ++;
		if (!ft[x]) ft[x] = i; lt[x] = i;
		num = max(num, ct[x]);
	}
	int ans1 = 1, ans2 = n;
	for (int i = 1; i <= 1000000; i++)
		if (ct[i] == num)
			if (lt[i] - ft[i] < ans2 - ans1){
				ans2 = lt[i], ans1 = ft[i];
			}
	printf("%d %d\n", ans1, ans2);
	return 0;
}

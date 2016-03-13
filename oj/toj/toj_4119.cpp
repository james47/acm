/*************************************************************************
    > File Name: toj_4119.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sun Aug  2 19:09:21 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int T, n, x;
long long sum;
int a[33][2];
int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		sum = n * (n + 1);
		n = n * 2 - 2;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++){
			scanf("%d", &x);
			sum -= x;
			for (int j = 0; j < 32; j++)
				if (x&(1<<j)) a[j][1] ^= x;
				else a[j][0] ^= x;
		}
		bool find = false;
		for (int i = 0; i < 32; i++){
			if (a[i][0] != 0 && a[i][1] != 0 && a[i][0] != a[i][1]){
				printf("%d %d\n", min(a[i][0], a[i][1]), max(a[i][0], a[i][1]));
				find = true;
				break;
			}
		}
		if (!find)
			printf("%d %d\n", int(sum/2), int(sum/2));
	}
	return 0;
}

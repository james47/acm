/*************************************************************************
  > File Name: c.cpp
  > Author: james47
  > Mail: 
  > Created Time: Wed Jul 15 13:23:25 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int n, comf;
bool flagnot2;
int ct[100100], a[100100], b[100100];
bool check(int x){
	int i = 1;
	while(i < x){
		i *= 2;
	}
	if (i == x) return false;
	else return true;
}
int main()
{
	scanf("%d", &n);
	comf = 0; flagnot2 = false;
	memset(ct, 0, sizeof(ct));
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
		while(b[i] % 2 == 0){
			b[i] /= 2;
			ct[i] ++;
		}
		if (comf == 0 || comf == b[i]) comf = b[i];
		else flagnot2 = true;
	}
	int ans = 0;
	if (flagnot2){
		for (int i = 0; i < n; i++){
			if (b[i] == 1){ continue; }
			ans += ct[i];
			while(b[i] != 1 && check(b[i])){
				ans++;
				b[i] /= 2;
			}
			if (b[i] == 1) ct[i] = 0; 
			else{
				ct[i] = 0;
				while(b[i] > 1){
					b[i] /= 2; ct[i] ++;
				}
			}
		}
	}
	int ans1 = 100000000;
	int tmp;
	for (int i = 1, j = 0; i <= 100000; i *= 2, j++){
		tmp = 0;
		for (int k = 0; k < n; k++){
			tmp += abs(j - ct[k]);
		}
		ans1 = min(ans1, tmp);
	}
	printf("%d\n", ans + ans1);
	return 0;
}

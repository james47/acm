/*************************************************************************
    > File Name: cc.cpp
    > Author: james47
    > Mail: 
    > Created Time: Wed Jul 15 14:08:25 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = (int)1e5 + 100;
int n, size, e2[100];
int a[maxn], b[maxn];
int ct[maxn], ct1[maxn];

int find(int x){
	for (int i = 0; i <= size; i++)
		if (e2[i] == x) return i;
	return -1;
}
int main()
{
	for (int i = 1, j = 0; i <= maxn; i *= 2, j++){
		e2[j] = i;
		size = j;
	}
	scanf("%d", &n);
	memset(ct, 0, sizeof(ct));
	memset(ct1, 0, sizeof(ct1));
	int comf = 0;
	bool reduce = false;
	for (int i = 0; i < n; i++){
		scanf("%d", a+i);
		b[i] = a[i];
		while(b[i] % 2 == 0){
			b[i] /= 2; ct[i]++;
		}
		if (comf == 0 || b[i] == comf) comf = b[i];
		else reduce = true;
		while(-1 == find(b[i])){
			b[i] /= 2; ct1[i] ++;
		}
	}
	int ans = 0;
	if (reduce){
		for (int i = 0; i < n; i++){
			ans += ct1[i];
			if (ct1[i]){
				ans += ct[i];
				ct[i] = find(b[i]);
			}
		}
	}
	int ans0 = 100000000;
	int tmp;
	for (int j = 0; j <= size; j++){
		tmp = 0;
		for (int i = 0; i < n; i++){
			tmp += abs(j - ct[i]);
		}
		ans0 = min(ans0, tmp);
	}
	printf("%d\n", ans+ans0);
	return 0;
}

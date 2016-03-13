/*************************************************************************
    > File Name: a.cpp
    > Author: james47
    > Mail: 
    > Created Time: Thu Sep 17 00:31:26 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int a, b;
int main()
{
	scanf("%d %d", &a, &b);
	if (b > a){ puts("-1"); return 0; }
	if (a % b == 0 && ((a/b)&1)){
		printf("%.10f\n", (double)b);
		return 0;
	}
	int p = a/b;
	if (p&1){
		printf("%.10f\n", (double)(a+b)/(p+1));
	}
	else{
		printf("%.10f\n", (double)(a+b)/p);
	}
	return 0;
}

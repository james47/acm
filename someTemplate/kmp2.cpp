#include <cstdio>
#include <cstring>

/*
i-f[i] 为最小循环节
P[i] A B R A C A D A B R A '\0'
f[i] 0 0 0 0 1 0 1 0 1 2 3 4 
*/
void getfail(char* P, int *f){
	int m = strlen(P);
	f[0] = f[1] = 0;
	for (int i = 1; i < m; i++){
		int j = f[i];
		while (j && P[i] != P[j]) j = f[j];
		f[i+1] = P[i] == P[j]? j+1: 0;
	}
}
void match(char* T, char* P, int* f){
	int n = strlen(T), m = strlen(P);
	getfail(P, f);
	int j = 0;
	for (int i = 0; i < n; i++){
		while(j && P[j] != T[i]) j = f[j];
		if (P[j] == T[i]) j++;
		if (j == m) printf("%d\n", i-m+1);
	}
}

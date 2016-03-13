/*************************************************************************
    > File Name: 04.cpp
    > Author: james47
    > Mail: 
    > Created Time: Tue Jul 28 12:20:49 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int T, n, M;
char m[100][100], c[100][100];
int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%s", m[i]);
		M = strlen(m[0]);
		char ch;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < M; j++){
				ch = m[i][j];
				if (ch == '.') ch = 0;
				else if (ch == 'R') ch = 1;
				else if (ch == 'B') ch = 2;
				else ch = 3;
				m[i][j] = ch;
			}
		int ans = 0;
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < M; j++){
				if (c[i][j] == m[i][j]) continue;
				if ((m[i][j]&1) && !(c[i][j]&1)){
					ans ++;
					for (int k = 0; ; k++){
						int ii = i+k, jj = j+k;
						if (ii >= n || jj >= M) break;
						if (m[ii][jj]&1){
							c[ii][jj] |= 1;
						}
						else break;
					}
				}
				if ((m[i][j]&2) && !(c[i][j]&2)){
					ans++;
					for (int k = 0; ; k++){
						int ii = i+k, jj = j-k;
						if (ii >= n || jj < 0) break;
						if (m[ii][jj]&2){
							c[ii][jj] |= 2;
						}
						else break;
					}
				}
			}
		printf("%d\n", ans);
	}
	return 0;
}

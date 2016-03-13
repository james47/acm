#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<ctime>
#include<string>
using namespace std;

int n;
int c[900][900], a[900][900], b[900][900];
inline int in()
{
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	int ans = 0;
	while(ch >= '0' && ch <= '9'){
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans;	
}
void multi(int c[][900], int a[][900], int b[][900])
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			if (a[i][j] == 0) continue;
			for (int k = 1; k <= n; k++){
				c[i][k] += a[i][j]  * b[j][k];
				//c[i][j] %= 3;
			}
		}
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++){
				//scanf("%d", &a[i][j]);
				a[i][j] = in();
				a[i][j] %= 3;
			}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++){
				//scanf("%d", &b[i][j]);
				b[i][j] = in();
				b[i][j] %= 3;
			}
		memset(c, 0, sizeof(c));
		multi(c, a, b);
		for (int i = 1; i <= n; i++){
			for (int j = 1; j < n; j++)
				printf("%d ", c[i][j] % 3);
			printf("%d\n", c[i][n] % 3);
		}
	}
	return 0;
}


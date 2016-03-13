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

struct node{
	int r, c, t;
} l[3000],ZERO;
bool cmp(node a, node b)
{
	return a.t < b.t;
}
int T, n, m, f, k, now;
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1},
    dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
char s[2][60][60];
int main()
{
	ZERO.r = ZERO.c = ZERO.t = 0;
	scanf("%d", &T);
	while(T--)
	{
		memset(s,0,sizeof(s));
		scanf("%d %d %d %d", &n, &m, &f, &k);
		for (int i = 0; i < n; i++) scanf("%s", s[0][i]);
		for (int i = 0; i < k; i++) scanf("%d %d %d", &l[i].t, &l[i].r, &l[i].c);
		sort(l, l + k, cmp);
		int pos = 0;
		while(pos < k && l[pos].t == 0){
			int x = l[pos].r-1, y = l[pos].c-1;
			s[0][x][y] = 'X';
			pos++;
		}
		now = 0;
		for (int t = 1; t <= f; t++){
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
				{
					if (s[now][i][j] == 'X'){
						s[now^1][i][j] = 'X';
						continue;
					}
					int x, y, cnt = 0;;
					for (int k = 0; k < 8; k++){
						x = i + dx[k], y = j + dy[k];
						if (x < 0 || y < 0 || x >= n || y >= m) continue;
						if (s[now][x][y] == '1') cnt++;
					}
					if (s[now][i][j] == '1'){
						if (cnt == 2 || cnt == 3) s[now^1][i][j] = '1';
						else s[now^1][i][j] = '0';
					}
					else{
						if (cnt == 3) s[now^1][i][j] = '1';
						else s[now^1][i][j] = '0';
					}
				}
			now ^= 1;
			int x, y;
			while(pos < k && l[pos].t == t){
				x = l[pos].r-1, y = l[pos].c-1;
				s[now][x][y] = 'X';
				pos++;
			}
		}
		for (int i = 0; i < n ; i ++)
		{
			s[0][i][m] = s[1][i][m] = '\0';
		}
		for (int i = 0; i < n; i++)
			printf("%s\n", s[now][i]);
	}
	return 0;
}

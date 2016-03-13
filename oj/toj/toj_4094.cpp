#include<cstdio>
#include<cstring>
using namespace std;


int n, m;
int a[210][210];
int dx[] = {0, 1, 0, -1},
    dy[] = {1, 0, -1, 0};
bool in(int x, int y)
{
	if (x < 0 || y < 0 || x > n-1 || y > m-1) return false;
	return true;
}
void dfs(int dep, int x, int y, int dir)
{
	if (dep == n * m) return;
	int xx = x + dx[dir], yy = y + dy[dir];
	while(in(xx, yy) && a[xx][yy] == 0){
		a[xx][yy] = ++ dep;
		x = xx, y = yy;
		xx = x + dx[dir], yy = y + dy[dir];
	}
	dfs(dep, x, y, (dir+1)%4);
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		memset(a, 0, sizeof(a));
		dfs(0, 0, -1, 0);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				printf("%d%c", a[i][j], j == m-1? '\n': ' ');
	}
	return 0;
}

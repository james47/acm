#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct que{
	int x, y;
} q[30000];
int n, m;
int dx[] = {0, 1},
    dy[] = {1, 0};
char str[110][110];
bool vis[110][110], map[110][110];
bool bfs(int sx, int sy, int ex, int ey)
{
	if (sx == ex && sy == ey) return 1;
	int head, tail;
	head = tail = 0;
	q[tail].x = sx;
	q[tail++].y = sy;
	memset(vis, 0, sizeof(vis));
	vis[sx][sy] = true;
	while (head < tail)
	{
		int x = q[head].x, y = q[head++].y;
		for (int i = 0; i < 2; i++){
			int xx = x + dx[i], yy = y + dy[i];
			if (xx > ex || yy > ey) continue;
			if (vis[xx][yy] || !map[xx][yy]) continue;
			vis[xx][yy] = 1;
			if (xx == ex && yy == ey) return true;
			q[tail].x = xx;
			q[tail++].y = yy;
		}
	}
	return false;
}
int main()
{
	while(scanf("%d %d", &m, &n) != EOF)
	{
		for (int i = 0; i < n; i++) scanf("%s", str[i]);
		memset(map, 1, sizeof(map));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (str[i][j] == 'X') map[i][j] = 0;
		int ans = -1;
		if (!bfs(0, 0, n-1, m-1)){
			printf("%d\n", ans);
			continue;
		}
		ans = n+m-2;
		for (int i = 0; i <= n-1; i++){
			for (int j = 0; j <= m-1; j++){
				if (i == 0 && j == 0) continue;
				if (ans <= i+j) break;
				memset(map, 1, sizeof(map));
				int nx = 0, ny = 0, ex = -1, ey = -1;
				while(nx < n && ny < m) nx += i, ny += j;
				if (nx < n-1 || ny < m-1) continue;
				nx = ny = 0;
				while(nx < n && ny < m){
					for (int k = nx; k <= nx + i; k ++)
						for (int l = ny; l <= ny + j; l++)
							if (k < n && l < m && str[k][l] == 'X') map[k-nx][l-ny] = 0;
					if (n-1 <= nx+i && m-1 <= ny+j){
						ex = n-1 - nx;
						ey = m-1 - ny;
						if (!map[0][0] || !map[ex][ey] || !map[i][j]) { ex = -1; break;}
					}
					nx += i; ny += j;
				}
				if (ex == -1) continue;
				if (bfs(0, 0, ex, ey) && bfs(ex, ey, i, j)) ans = i+j;
			}
		}
		printf("%d\n", ans);
	}	
	return 0;
}

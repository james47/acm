#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct que{
	int x, y, d;
} q[3000];
int T, n, m, stx, sty, edx, edy;
char str[30];
int map[60][60];
bool vis[60][60];
int dx[] = {1, -1, 0, 0},
    dy[] = {0, 0, 1, -1};
void init()
{		
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%s", str);
			if (str[0] != 'X'){
				map[i][j] = 1;
				if (str[0] == 'S') stx = i, sty = j;
				else if (str[0] == 'R') edx = i, edy = j;
			}
			else map[i][j] = 0;
		}
	}
}
int bfs(int stx, int sty, int edx, int edy)
{
	memset(vis, 0, sizeof(vis));
	int head, tail;
	head = tail = 0;
	q[tail].x = stx, q[tail].y = sty, q[tail].d = 0;
	tail ++;
	vis[stx][sty] = true;
	while (head < tail)
	{
		int x = q[head].x, y = q[head].y, d = q[head].d;
		head ++;
		for (int i = 0; i < 4; i++){
			for (int j = 1; j <= 3; j++){
				int xx = x + j * dx[i], yy = y + j * dy[i];
				if (xx < 0 || yy < 0 || xx > n-1 || yy > m-1) continue;
				if (vis[xx][yy] || !map[xx][yy]) continue;
				if (xx == edx && yy == edy) return d + 1;
				vis[xx][yy] = true;
				q[tail].x = xx, q[tail].y = yy;
				q[tail++].d = d + 1;
			}
		}
	}
	return -1;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		init();
		printf("%d\n", bfs(stx, sty, edx, edy));
	}
	return 0;
}

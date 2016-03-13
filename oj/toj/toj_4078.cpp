#include<cstdio>
#include<cstring>
using namespace std;

struct quene
{
		int x, y;
		bool up;
} q[5000];
bool reach;
bool block[110][3];
bool flag[110][110][2];
int h, t;

void bfs(int h)
{
		int x = q[h].x, y = q[h].y;
		if (x == 100 && y == 0)
		{
				reach = true;
				return;
		}
		int nx = x + 1, ny;
		if (nx > 100) return;
		if (y == 0)
		{
				ny = 0;
				if (!flag[nx][ny][0] && !block[nx][ny])
				{
						flag[nx][ny][0] = true;
						q[t].x = nx;
						q[t].y = ny;
						t++;
				}
				ny = 1;
				if (!flag[nx][ny][1] && !block[nx][ny])
				{
						flag[nx][ny][1] = true;
						q[t].x = nx;
						q[t].y = ny;
						q[t].up = true;
						t++;
				}
		}
		if (y == 1)
		{
				bool up = q[h].up;
				if (up)
						ny = 2;
				else
						ny = 0;
				if (!flag[nx][ny][0] && !block[nx][ny])
				{
						flag[nx][ny][0] = true;
						q[t].x = nx;
						q[t].y = ny;
						t++;
				}
		}
		if (y == 2)
		{
				ny = 1;
				if (!flag[nx][ny][0] && !block[nx][ny])
				{
						flag[nx][ny][0] = true;
						q[t].x = nx;
						q[t].y = ny;
						q[t].up = false;
						t++;
				}
		}
		return;
}
int main()
{
		int n;
		while (scanf("%d", &n) != EOF)
		{
				memset(block, false, sizeof(block));
				memset(flag, false, sizeof(flag));
				int x, y;
				for (int i = 0; i < n; i++)
				{
						scanf("%d%d", &x, &y);
						block[x][y] = true;
				}
				h = 0; t = 0;
				q[t].x = 0;
				q[t].y = 0;
				flag[0][0][0] = true;
				t++;
				reach = false;
				while (h < t)
				{
						bfs(h);
						h++;
						if (reach) break;
				}
				if (reach)
						printf("1\n");
				else
						printf("0\n");
		}
		return 0;
}

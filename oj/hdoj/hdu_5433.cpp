/*************************************************************************
    > File Name: b.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sat Sep 12 19:40:44 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-6;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
struct node{
	int x, y, k;
	node(){}
	node(int x, int y, int k): x(x), y(y), k(k){}
};
const int mod = 55*55*55*4;
int T;
char mp[55][55];
int n, m, tot;
int stx, sty, edx, edy;
double dp[55][55][55];
bool inq[55][55][55];
node q[mod+5];
int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d", &n, &m, &tot);
		for (int i = 0; i < n; i ++) scanf("%s", mp[i]);
		scanf("%d %d %d %d", &stx, &sty, &edx, &edy);
		if (tot == 0){
			puts("No Answer");
			continue;
		}
		stx --, sty --, edx --, edy --;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				for (int k = 0; k <= tot; k++){
					dp[i][j][k] = 1e10;
					inq[i][j][k] = false;
				}
		int head = 0, tail = 0;
		dp[stx][sty][tot] = 0.0; inq[stx][sty][tot] = true;
		q[tail++] = node(stx, sty, tot);
		while(head != tail){
			node u = q[head++]; if (head == mod) head = 0;
			for (int i = 0; i < 4; i++){
				int x = u.x + dx[i], y = u.y + dy[i];
				if (x < 0 || y < 0 || x >= n || y >= m) continue;
				if (mp[x][y] == '#') continue;
		//		printf("%d\n", u.k);
		//		printf("%.2f\n", (double)abs(mp[x][y] - mp[u.x][u.y])/u.k);
				double tmp = dp[u.x][u.y][u.k] + (double)abs(mp[x][y] - mp[u.x][u.y])/u.k;
				if (tmp + eps < dp[x][y][u.k-1]){
					dp[x][y][u.k-1] = tmp;
					if (x != edx || y != edy){
						if (u.k-1 != 0 && !inq[x][y][u.k-1]){
							inq[x][y][u.k-1] = true;
							q[tail++] = node(x, y, u.k-1);
							if (tail == mod) tail = 0;
						}
					}
				}
			}
			inq[u.x][u.y][u.k] = false;
		}
		double ans = 1e10;
		for (int i = 0; i <= tot; i++)
			ans = min(ans, dp[edx][edy][i]);
		if (fabs(ans - 1e10) < eps) puts("No Answer");
		else printf("%.2f\n", ans);
	}
	return 0;
}

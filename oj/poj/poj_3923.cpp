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

struct point{
	int r, c;
} st[100];
bool vis[300][300];
int anssize, n, m;
int ct[100];
char str[300][300], ans[100];
int dr[] = {1, -1, 0, 0},
    dc[] = {0, 0, 1, -1};
int lx[30],
    ly[30];
bool check(int id)
{
	int cnt = 0;
	int rr = st[id].r, cc = st[id].c;
	int start = rr, end = cc;
	bool flag = false;
	while(cnt < ct[id]){
		//printf("%d %d %d\n", rr, cc, cnt);
		vis[rr][cc] = true;
		cnt ++;
		int i, nr, nc;
		for (i = 0; i < 4; i++){
			nr = rr + dr[i],
			nc = cc + dc[i];
			if (nr > n-1 || nc > m-1 || nr < 0 || nc < 0)
				continue;
			if (cnt == ct[id] && nr == start && nc == end) flag = true;
			if (vis[nr][nc] || str[nr][nc] - 'A' != id) continue;
			break;
		}
		if (i == 4) break;
		else{
			rr = nr;
			cc = nc;
		}
	}
	bool flag2 = true;
	char tmp = id + 'A';
	for (int i = lx[id]; i <= start; i++){
		if (!flag2) break;
		for (int j = ly[id]; j <= end; j++)
			if (str[i][j] != '.' && str[i][j] != tmp){
				flag2 = false;
				break;
			}
	}
	if (cnt == ct[id] && flag && flag2) return true;
	else return false;
}
int main()
{
	while(scanf("%d %d", &n, &m) && (n+m))
	{
		memset(st, 0, sizeof(st));
		memset(vis, false, sizeof(vis));
		memset(ct, 0, sizeof(ct));
		for (int i = 0; i < n; i++){
			scanf("%s", str[i]);
			for (int j = 0; j < m; j++){
				if (str[i][j] != '.'){
					ct[str[i][j]-'A'] ++;
					if (ct[str[i][j]-'A'] == 1){
						lx[str[i][j]-'A'] = i;
						ly[str[i][j]-'A'] = j;
					}
					st[str[i][j]-'A'].r = i;
					st[str[i][j]-'A'].c = j;
				}
			}
		}
		anssize = 0;
		for (int i = 0; i < 26; i++)
			if (ct[i]){
				if (check(i)){
					ans[anssize++] = i + 'A';
				}
			}
		ans[anssize] = '\0';
		printf("%s\n", ans);
	}
	return 0;
}

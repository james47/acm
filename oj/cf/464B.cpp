#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
int P[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2},
		  {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
LL dis[10];
int a[10][5], b[10][5], p[10];
bool findans;

bool check()
{
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			dis[j] = 0;
			for (int k = 0; k < 3; k++)
				dis[j] = dis[j] + (LL)(b[i][k]-b[j][k]) * (b[i][k]-b[j][k]);
		}
		sort(dis, dis+8);
		LL len = dis[1];
		if (len == 0) return false;
		if (dis[1] != dis[2] || dis[1] != dis[3]) return false;
		if (dis[4] != len * 2) return false;
		if (dis[4] != dis[5] || dis[4] != dis[6]) return false;
		if (dis[7] != len * 3) return false;
	}
	return true;
}
void dfs(int dep)
{
	if (findans) return;
	if (dep == 8){
		for (int i = 0; i < 8; i++){
			int id = p[i];
			for (int j = 0; j < 3; j++){
				b[i][j] = a[i][P[id][j]];
			}
		}
		if (check()){
			findans = true;
			puts("YES");
			for (int i = 0; i < 8; i++){
				for (int j = 0; j < 3; j++)
					printf("%d%c", b[i][j], j==2?'\n':' ');
			}
		}
		return;
	}
	for (int i = 0; i < 6; i++){
		p[dep] = i;
		dfs(dep+1);
	}
}
void solve()
{
	p[0] = 0;
	findans = false;
	dfs(1);
	if (!findans) puts("NO");
	return;
}
int main()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
	solve();
	return 0;
}

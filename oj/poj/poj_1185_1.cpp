#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m, cnt, size;
int a[110], st[70], ct[70];
char str[15];
bool vis[1200], tmp[15];
int f[110][70][70];
void dfs(int nex)
{
	if (nex > m){
		int x = 0, cnt = 0;
		for (int i = 1; i <= m; i++)
			if (tmp[i]) cnt++, x += 1 << (i-1);
		if (!vis[x]){
			vis[x] = true;
			st[size] = x;
			ct[size++] = cnt;
		}
		return;
	}
	dfs(nex+1);
	tmp[nex] = true;
	dfs(nex+3);
	tmp[nex] = false;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%s", str);
		int x = 0;
		for (int j = 0; j < m; j++){
			if (str[j] == 'H') x += 1 << j;
		}
		a[i] = x;
	}
	memset(tmp, 0, sizeof(tmp));
	memset(vis, 0, sizeof(vis));
	size = 0;
	dfs(0);
	memset(f, 0, sizeof(f));
	for (int j = 0; j < size; j++){
		if (!(a[1]&st[j])) f[1][j][0] = ct[j];
	}
	for (int i = 2; i <= n; i++){
		for (int j = 0; j < size; j++){
			if (a[i]&st[j]) continue;
			for (int k = 0; k < size; k++){
				if (a[i-1]&st[k]) continue;
				if (i == 2){
					if (!(st[j]&st[k]))
						f[i][j][k] = max(f[i][j][k], f[i-1][k][0] + ct[j]);
				}
				else for (int l = 0; l < size; l++){
					if (!(a[i-2]&st[l]) && !(st[j]&st[k]) && !(st[j]&st[l]) && !(st[k]&st[l]))
						f[i][j][k] = max(f[i][j][k], f[i-1][k][l] + ct[j]);
				}
			}
		}
	}
	int ans = 0;
	for (int j = 0; j < size; j++)
		for (int k = 0; k < size; k++)
			ans = max(ans, f[n][j][k]);
	printf("%d\n", ans);
	return 0;
}



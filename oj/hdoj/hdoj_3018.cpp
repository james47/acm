#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

int in[100100], f[100100], od[100100], ev[100100];
int n, m, a, b;
int getf(int x)
{
	if (x == f[x]) return x;
	f[x] = getf(f[x]);
	return f[x];
}
void unionxy(int x, int y)
{
	f[getf(x)] = getf(f[y]);
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 0; i <= n; i++)
			f[i] = i;
		memset(in, 0, sizeof(in));
		for (int i = 0; i < m; i++){
			scanf("%d %d", &a, &b);
			unionxy(a, b);
			in[a] ++;
			in[b] ++;
		}
		map<int, int> mp;
		int cnt = 1;
		memset(od, 0, sizeof(od));
		memset(ev, 0, sizeof(ev));
		for (int i = 1; i <= n; i++){
			int col = getf(i);
			if (mp[col] == 0)
				mp[col] = cnt++;
			if (in[i] & 1 == 1) od[mp[col]] ++;
			else if (in[i] != 0) ev[mp[col]] ++;
		}
		int ans = 0;
		for (int i = 1; i < cnt; i++){
			if (od[i]) ans += od[i]/2;
			else if (ev[i]) ans ++;
		}
		printf("%d\n", ans);
	}
	return 0;
}

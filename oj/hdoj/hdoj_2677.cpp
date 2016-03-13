#include<cstring>
#include<cstdio>
using namespace std;

int tot;
char s[110];
struct wupin
{
	char n[110];
	int v, have, need;
} p[110];
int b[110];
int c[110][110];
int find(char s[])
{
	int i;
	for (i = 0; i < tot; i++)
		if (!strcmp(s, p[i].n)) break;
	if (i == tot)
	{
		strcpy(p[i].n, s);
		tot ++;
	}
	return i;
}
int main()
{
	int n1, n2, n3, n4;
	while(scanf("%d", &n1) != EOF)
	{
		memset(p, 0, sizeof(p));
		memset(c, 0, sizeof(c));
		memset(b, 0, sizeof(b));
		for (int i = 0; i < n1; i++)
		{
			scanf("%s %d", p[i].n, &p[i].v);
		}
		tot = n1;
		scanf("%d", &n2);
		for (int i = 0; i < n2; i++)
		{
			int x;
			scanf("%s %d", s, &x);
			p[find(s)].have += x;
		}
		scanf("%d", &n3);
		int cnt = 0;
		while (cnt < n3)
		{
			int size = 0;
			while(scanf("%s", s) && strcmp(s, "="))
			{
				if (!strcmp(s, "+")) continue;
				c[cnt][++size] = find(s);
			}
			c[cnt][0] = size;
			scanf("%s", s);
			b[cnt] = find(s);
			cnt++;
		}
		scanf("%d", &n4);
		for (int i = 0; i < n4; i++)
		{
			int x;
			scanf("%s %d", s, &x);
			p[find(s)].need += x;
		}
		bool change = true;
		while(change)
		{
			change = false;
			for (int i = 0; i < tot; i++)
			{
				if (p[i].need > 0 && p[i].have > 0)
				{
					if (p[i].need > p[i].have)
					{
						p[i].need -= p[i].have;
						p[i].have = 0;
					}
					else
					{
						p[i].have -= p[i].need;
						p[i].need = 0;
					}
				}
			}
			for (int i = 0; i < cnt; i++)
			{
				if (p[b[i]].need > 0)
				{
					for (int j = 1; j <= c[i][0]; j++)
					{
						int y = c[i][j];
						p[y].need += p[b[i]].need;
					}
					p[b[i]].need = 0;
					change = true;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < tot; i++)
			if (p[i].need > 0)
				ans += p[i].need * p[i].v;
		printf("%d\n", ans);
	}
	return 0;
}

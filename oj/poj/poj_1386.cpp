#include<cstdio>
#include<cstring>
using namespace std;

char s[2000];
int in[50], ch[50], f[50];
bool c[50];
int n;
int getf(int x)
{
	if (x == f[x]) return x;
	f[x] = getf(f[x]);
	return f[x];
}
void unionxy(int x, int y)
{
	int xroot = getf(x),
	    yroot = getf(y);
	f[xroot] = yroot;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		memset(in, 0, sizeof(in));
		memset(ch, 0, sizeof(ch));
		memset(c, 0, sizeof(c));
		for (int i = 0; i < 26; i++)
			f[i] = i;
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%s", s);
			int x = s[0] - 'a',
			    y = s[strlen(s)-1] - 'a';
			ch[x] ++; in[y] ++;
			c[x] = 1; c[y] = 1;
			unionxy(x, y);
		}
		int cnt = 0;
		for (int i = 0; i < 26; i++)
			if (f[i] == i && c[i]) cnt++;
		if (cnt > 1){
			printf("The door cannot be opened.\n");
			continue;
		}
		int i, st = 0, ed = 0;
		for (i = 0; i < 26; i++) if (c[i]){
			if (ch[i] - in[i] == 1)
				st++;
			else if (in[i] - ch[i] == 1)
				ed++;
			else if (in[i] != ch[i]) break;
		}
		bool ok = true;
		if (i < 26) ok = false;
		if (!((st == 0 && ed == 0)||(st == 1 && ed == 1)))
			ok = false;
		if (ok)
			printf("Ordering is possible.\n");
		else printf("The door cannot be opened.\n");
	}
	return 0;
}

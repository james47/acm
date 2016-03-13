#include<cstdio>
#include<cstring>
using namespace std;

int n, p;
bool e[110][310];
int match[310], f[310], lm[110];
int path(int s){
	int i;
	for (i = 1; i <= n; i++){
		if (f[i] == 0 && e[s][i] == 1){
			f[i] = 1;
			if (match[i] == 0 || path(match[i])){
				match[i] = s; lm[s] = i;
				return 1;
			}
		}
	}
	return 0;
}
int maxmatch(){
	int ret = 0;
	memset(lm, 0, sizeof(lm));
	memset(match, 0, sizeof(match));
	for (int i = 1; i <= p; i++)
		for (int j = 1; !lm[i] && j <= n; j++)
			if (e[i][j] && !match[j]){
				match[j] = i; lm[i] = j; ret++;
			}
	for (int i = 1; i <= p; i++){
		if (!lm[i]){
			memset(f, 0, sizeof(f));
			if (path(i)) ret++;
		}
	}
	return ret;
}
int T;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		memset(e, 0, sizeof(e));
		scanf("%d %d", &p, &n);
		for (int i = 1; i <= p; i++){
			int t;
			scanf("%d", &t);
			for (int j = 0; j < t; j++){
				int to;
				scanf("%d", &to);
				e[i][to] = 1;
			}
		}
		int ans = maxmatch();
		if (ans >= p) puts("YES");
		else puts("NO");
	}
	return 0;
}

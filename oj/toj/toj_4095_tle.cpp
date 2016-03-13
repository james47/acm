#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T, n, ans;
int w[40];
long long D, tot[40];
void dfs(int dep, int cnt, long long sum)
{
	if (ans == -2) return;
	if (sum == D){
		if (ans == -1 || ans == cnt) ans = cnt;
		else ans = -2;
		return;
	}
	if (dep == n) return;
	for (int i = dep+1; i < n; i++){
		if (tot[i] + sum <= D){
			dfs(n-1, n-i+cnt, tot[i]+sum);
			return;
		}
		long long tmp = sum + w[i];
		if (tmp <= D) dfs(i, cnt+1, tmp);
		if (ans == -2) return;
	}
}
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	scanf("%d", &T);
	int cas = 0;
	while (T--)
	{
		scanf("%d %lld", &n, &D);
		for (int i = 0; i < n; i++) scanf("%d", w+i);
		sort(w, w+n, cmp);
		tot[n] = 0;
		for (int i = n-1; i >= 0; i--)
			tot[i] = tot[i+1] + w[i];
		ans = -1;
		dfs(-1, 0, 0);
		printf("Case #%d: ", ++cas);
		if (ans == -1) printf("IMPOSSIBLE\n");
		else if (ans == -2) printf("AMBIGIOUS\n");
		else printf("%d\n", ans);
	}
	return 0;
}

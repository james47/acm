#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxcut = 3000000;
int T, n, ans, num, cut;
int w[40];
long long D, tot[40], Sum;
bool v[40];
void dfs(int pos, int cnt, long long sum, int lim)
{
	if (v[lim] && v[n-lim]) return;
	if (cnt == lim){
		if (sum == D){
			if (!v[cnt]){
				v[cnt] = true;
				num ++;
				ans = cnt;
			}
		}
		if (Sum - sum == D){
			if (!v[n-cnt]){
				v[n-cnt] = true;
				num ++;
				ans = n - cnt;
			}
		}
		return;
	}
	cut ++;
	if (cut > maxcut) return;
	for (int i = pos+1; i < n; i++){
		if (n - i < lim - cnt) break;
		long long tmp = sum + w[i];
		dfs(i, cnt+1, tmp, lim);
		if (v[lim] && v[n-lim]) return;
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
		cut = 0;
		memset(v, 0, sizeof(v));
		scanf("%d %lld", &n, &D);
		Sum = 0;
		bool flag = false;
		for (int i = 0; i < n; i++){
			scanf("%d", w+i);
			Sum = Sum + w[i];
			if (w[i] == 0) flag = true;
		}
		sort(w, w+n, cmp);
		ans = -1; num = 0;
		for (int i = 0; i <= n/2; i++){
			dfs(-1, 0, 0, i);
			if (flag && ans != -1 && D != 0) num ++;
			if (num >= 2) break;
		}
		printf("Case #%d: ", ++cas);
		if (num == 0) printf("IMPOSSIBLE\n");
		else if (num >= 2) printf("AMBIGIOUS\n");
		else printf("%d\n", ans);
	}
	return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

bool flag;
int n, k, l;
int need, ans;
bool vis[130], use[30];
int a[30], b[30], c[30];
int cal()
{
	memset(vis, false, sizeof(vis));
	int tmp;
	for (int i = 0; i < k; i++){
		tmp = 0;
		for (int j = 0; j < k; j++){
			int pos = i + j;
			if (pos > k-1) pos -= k;
			tmp ^= c[pos];
			vis[tmp] = true;
		}
	}
	if (!vis[l]) return 0;
	for (int i = l+1; i <= 200; i++)
		if (!vis[i]) return i - 1;
}
bool check(int dep, int pre)
{
	//printf("dep %d pre %d\n", dep, pre);
	/*
	if (pre == need) return true;
	if (dep == k) return false;
	bool flag = check(dep+1, pre^b[dep]);
	if (!flag) flag = check(dep+1, pre);
	return flag;
	*/
	if (dep == k){
		for (int i = l; i <= 200; i++)
			if (!vis[i]){
				flag = (i-1) >= need;
				return 0;
			}
	}
	vis[pre] = true;
	vis[pre^b[dep]] = true;
	check(dep+1, pre);
	check(dep+1, pre^b[dep]);
	return 0;
}
void dfs2(int dep)
{
	if (dep == k){
		int tmp = cal();
		//	printf("%d\n", tmp);
		if (tmp > ans){
			ans = tmp;
			need = tmp + 1;
		}
		return;
	}
	for (int i = 0; i < k; i++)
		if (!use[i]){
			use[i] = true;
			c[dep] = b[i];
			dfs2(dep+1);
			use[i] = false;
		}
}
void dfs(int dep, int pos)
{
	if (dep == k){
		memset(vis, 0, sizeof(vis));
		flag = false;
		check(0, 0);
		if (flag){
			/*
			   puts("in!\n b[]: ");
			   for (int i = 0; i < k; i++)
			   printf("%d ", b[i]);
			   puts("");
			 */
			dfs2(0);
		}
		return;
	}
	for (int i = pos+1; i < n && n-i >= k-dep; i++){
	//for (int i = pos + 1; i < n && n-1-i >= k-(dep+1); i++){
	//for (int i = pos+1; i < n; i++){
		b[dep] = a[i];
		dfs(dep+1, i);
	}
}
int main()
{
	memset(use, false, sizeof(use));
	while(scanf("%d%d%d", &n, &k, &l) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", a + i);
		sort(a, a+n);
		ans = 0, need = l;
		dfs(0, -1);
		printf("%d\n", ans);
	}
	return 0;
}
r(i);

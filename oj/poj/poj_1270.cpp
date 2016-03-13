#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

char s1[1000], s2[1000];
string ans[400];
int n, cnt;
bool vis[50], e[50][50];
int in[50], a[50];
void dfs(int dep, string ss)
{
	if (dep == n){
		ans[cnt++] = ss;
		return;
	}
	for (int i = 0; i < n; i++)
		if (!in[a[i]] && !vis[a[i]]){
			vis[a[i]] = true;
			char tmp = a[i] + 'a' - 1;
			ss.append(1, tmp);
			for (int j = 0; j < n; j++)
				if (e[a[i]][a[j]]) in[a[j]] --;
			
			dfs(dep+1, ss);

			vis[a[i]] = false;
			ss.erase(ss.length()-1, 1);
			for (int j = 0; j < n; j++)
				if (e[a[i]][a[j]]) in[a[j]] ++;
		}
	return;
}
bool cmp(string a, string b){
	return a < b;
}
int main()
{
	bool flag = true;
	while(cin.getline(s1, 1000))
	{
		if (flag) flag = false;
		else printf("\n");
		cin.getline(s2, 1000);
		n = 0;
		for (int i = 0; i < strlen(s1); i++){
			if (s1[i] != ' '){
				a[n++] = s1[i] - 'a' + 1;
			}
		}
//		for (int i = 0; i < n; i++)
//			printf("%d\n", a[i]);
		memset(e, 0, sizeof(e));
		memset(in, 0, sizeof(in));
		memset(vis, false, sizeof(vis));
		int p1 = 0, p2 = 0;
		for (int i = 0; i < strlen(s2); i++){
			if (s2[i] != ' '){
				if (p1 == 0){
					p1 = s2[i] - 'a' + 1;
				}
				else{
					p2 = s2[i] - 'a' + 1;
					e[p1][p2] = true;	
					in[p2] ++;
					p1 = p2 = 0;
				}
			}
		}
		string ss = "";
		cnt = 0;
		dfs(0, ss);
		sort(ans, ans+cnt, cmp);
		for (int i = 0; i < cnt; i++)
			cout << ans[i] << endl;
	}
	return 0;
}

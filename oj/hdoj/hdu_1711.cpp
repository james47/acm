#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;


int a[1000100], b[10100], next[10100];
void getnext(int* s2, int l2){
	int j = -1;
	next[0] = -1;
	for (int i = 1; i < l2; i++){
		while(j != -1 && s2[i] != s2[j+1]) j = next[j];
		if (s2[i] == s2[j+1]) next[i] = ++j;
		else next[i] = -1;
	}
	//for (int i = 0; i < l2; i++) printf("%d ", next[i]);
	//puts("");
}
vector<int> kmp(int* s1, int* s2, int l1, int l2){
	vector<int> ans; ans.clear();
	int i = 0, j = -1;
	for (int i = 0; i < l1; i++){
		while(j != -1 && s1[i] != s2[j+1]) j = next[j];
		if (s1[i] == s2[j+1]){
			j ++;
			if (j == l2-1){
				ans.push_back(i-l2+1);
				j = next[j];
			}
		}
	}
	return ans;
}

int T, n, m;
int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%d", a+i);
		for (int i = 0; i < m; i++)
			scanf("%d", b+i);
		getnext(b, m);
		vector<int> ans = kmp(a, b, n, m);
		if ((int)ans.size() == 0) puts("-1");
		else printf("%d\n", ans[0]+1);
	}
	return 0;
}

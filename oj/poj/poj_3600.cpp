#include<cstdio>
#include<cstring>
using namespace std;

int r, c, R, C;
int id[30];
char a[30][30], b[30][30];
bool dfs(int pos, int dep)
{
	if (dep == r){
		int cnt = 0, cur = 0;;
		while(cur < C && cnt < c){
			bool flag = true;
			for (int i = 0; i < r; i++)
				if (a[id[i]][cur] != b[i][cnt]){
					flag = false;
					break;
				}
			cur ++;
			if (flag) cnt ++;
		}
		if (cnt == c) return true;
		else return false;
	}
	for (int i = pos; i < R; i++){
		id[dep] = i;
		if (dfs(i+1, dep+1)) return true;
	}
	return false;
}
int main()
{
	while(scanf("%d %d", &r, &c) != EOF)
	{
		for (int i = 0; i < r; i++) scanf("%s", b[i]);
		scanf("%d %d", &R, &C);
		for (int i = 0; i < R; i++) scanf("%s", a[i]);
		if (dfs(0, 0)) puts("Yes");
		else puts("No");
	}
	return 0;
}

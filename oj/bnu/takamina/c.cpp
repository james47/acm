#include<cstdio>
#include<cstring>
using namespace std;

int n, m;
int a[110][110], b[110][110];
int row[110], col[110];
bool vrow[110], vcol[110];
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) scanf("%d", &b[i][j]);
	for (int i = 0; i < n; i++){
		bool flag = true;
		for (int j = 0; j < m; j++)
			if (b[i][j] == 0){
				flag = false;
				break;
			}
		if (flag) row[i] = true;
		else row[i] = false;
	}
	for (int j = 0; j < m; j++){
		bool flag = true;
		for (int i = 0; i < n; i++)
			if (b[i][j] == 0){
				flag = false;
				break;
			}
		if (flag) col[j] = true;
		else col[j] = false;
	}
	memset(vrow, 0, sizeof(vrow));
	memset(vcol, 0, sizeof(vcol));
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (row[i] && col[j]){
				vrow[i] = vcol[j] = true;
				a[i][j] = 1;
			}
	bool flag = true;
	for (int i = 0; i < n && flag; i++)
		for (int j = 0; j < m; j++)
			if (b[i][j]) if (!vrow[i] && !vcol[j]){
				flag = false; break;
			}
	if (!flag) puts("NO");
	else{
		puts("YES");
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				printf("%d%c", a[i][j], j==m-1?'\n':' ');
	}
	return 0;
}

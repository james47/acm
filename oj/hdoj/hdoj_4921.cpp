#include<cstdio>
#include<cstring>
using namespace std;

int T, n, m, x, y, tot;
int nex[10100], v[10100], line[15][1010];
bool head[10100];
double sum, sumv;
void dfs(int lv, int pos, int yi, int sumi, int xi, double sum)
{
	if (pos > tot){
		if (yi > 1){
			sumv += (double)yi * sumi / xi * sum;
		}
		return;
	}
	if (line[pos][0] < lv) 
		dfs(lv, pos+1, yi, sumi, xi, sum*(line[pos][0]+1));
	else{
		dfs(lv, pos+1, yi+1, sumi+v[line[pos][lv]], xi, sum*(line[pos][0]-lv+1));
		dfs(lv, pos+1, yi, sumi, xi, sum*lv);
	}
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%d", v+i);
		memset(head, 1, sizeof(head));
		memset(nex, -1, sizeof(nex));
		for (int i = 0; i < m; i++){
			scanf("%d %d", &x, &y);
			nex[x] = y;
			head[y] = 0;
		}
		tot = 0; sum = 1.0; sumv = 0;
		for (int i = 0; i < n; i++) if (head[i]){
			line[++tot][0] = 1;
			line[tot][1] = i;
			int now = i; int &cnt = line[tot][0];
			while (nex[now] != -1){
				now = nex[now];
				line[tot][++cnt] = now;
			}
		}
		for (int i = 1; i <= tot; i++)
			sum *= (double)(line[i][0] + 1);
		for (int i = 1; i <= tot; i++){
			int len = line[i][0];
			for (int j = 1; j <= len; j++){
				int k = line[i][j];
				if (tot == 1) sumv += (double)v[k] * (len - j + 1);
				else sumv += (double)v[k] * sum * (len - j + 1) / (len+1);
			}
		}
//		printf("%.3lf\n", sumv);
		if (tot > 1){
			int maxlv = 1;
			for (int i = 1; i <= tot; i++)
				if (line[i][0] > maxlv) maxlv = line[i][0];
			for (int i = 1; i <= maxlv; i++){
				int xi = 0;
				for (int j = 1; j <= tot; j++)
					if (line[j][0] >= i) xi++;
				dfs(i, 1, 0, 0, xi, 1.0); 
			}
		}
//		printf("%.3lf\n", sumv);
		printf("%.3lf\n", sumv/(sum-1.0));
	}
	return 0;
}

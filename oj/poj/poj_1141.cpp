#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


char s[200];
char mat[300];
int d[200][200], g[200][200];
bool pre[300], nex[300];
bool match(int a, int b, char s[])
{
	if (s[a] == '(' && s[b] == ')') return true;
	if (s[a] == '{' && s[b] == '}') return true;
	if (s[a] == '[' && s[b] == ']') return true;
	return false;
}
void output(int l, int r)
{
	if (l > r) return;
	if (g[l][r] == 0){
		printf("%c", s[l]);
		output(l+1, r-1);
		printf("%c", s[r]);
	}
	else if (g[l][r] == -1){
		if (pre[s[l]])
			printf("%c%c", s[l], mat[s[l]]);
		else
			printf("%c%c", mat[s[l]], s[l]);
		output(l+1, r);
	}
	else if (g[l][r] == -2){
		output(l, r-1);
		if (pre[s[r]])
			printf("%c%c", s[r], mat[s[r]]);
		else
			printf("%c%c", mat[s[r]], s[r]);
	}
	else if (g[l][r] == -3){
		printf("%c%c", s[l], s[r]);
	}
	else{
		output(l, g[l][r]);
		output(g[l][r]+1, r);
	}
}
int main()
{
	memset(pre, false, sizeof(pre));
	memset(nex, false, sizeof(nex));
	pre['('] = 1; pre['{'] = 1; pre['['] = 1;
	nex[')'] = 1; nex['}'] = 1; nex[']'] = 1;
	mat['('] = ')'; mat[')'] = '(';
	mat['{'] = '}'; mat['}'] = '{';
	mat['['] = ']'; mat[']'] = '[';
	while(gets(s))
	{
		memset(d, 127, sizeof(d));
		int len = strlen(s);
		for (int i = 0; i < len; i++){
			d[i][i] = 1;
			g[i][i] = -1;
		}
		for (int i = 0; i < len-1; i++)
			if (match(i, i+1, s)){
				d[i][i+1] = 0;
				g[i][i+1] = -3;
			}
		for (int k = 1; k < len; k++)
			for (int i = 0; i < len; i++){
				int j = i + k;
				if (j >= len) break;
				int tmp = d[i+1][j-1];// + 2 * (1 - match(i, j, s));
				if (match(i, j, s) && tmp < d[i][j]){
					d[i][j] = tmp;
					g[i][j] = 0;
				}
				tmp = d[i+1][j]+1;
				if (tmp < d[i][j]){
					d[i][j] = tmp;
					g[i][j] = -1;
				}
				tmp = d[i][j-1]+1;
				if (tmp < d[i][j]){
					d[i][j] = tmp;
					g[i][j] = -2; 
				}
				for (int m = i; m < j; m++){
					tmp = d[i][m] + d[m+1][j];
					if (tmp < d[i][j]){
						d[i][j] = tmp;
						g[i][j] = m;
					}
				}
			}
//		for (int i = 0; i < len; i++)
//			for (int j = i; j < len; j++)
//				printf("%d %d %d\n", i, j, d[i][j]);
	//	printf("%d\n", d[0][len-1]);	
		output(0, len-1);
		printf("\n");
	}
	return 0;
}

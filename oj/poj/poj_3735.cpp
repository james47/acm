#include<cstdio>
#include<cstring>
using namespace std;

struct mat{
	int row, col;
	long long m[110][110];
	mat operator *(const mat &p){
		mat ret;
		ret.row = row, ret.col = p.col;
		for (int i = 0; i < ret.row; i++)
			for (int j = 0; j < ret.col; j++)
				ret.m[i][j] = 0;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				if (m[i][j]){
					for (int k = 0; k < ret.col; k++)
						ret.m[i][k] += m[i][j] * p.m[j][k];
				}
		return ret;
	}
} En, M, tmp, ans;
mat pow(mat a, int n)
{
	if (n == 0) return En;
	if (n == 1) return a;
	ans = En; tmp = a;
	while(n){
		if (n & 1) ans = ans * tmp;
		tmp = tmp * tmp;
		n >>= 1;
	}
	return ans;
}
int n, m, k;
int main()
{
	memset(En.m, 0, sizeof(En.m));
	for (int i = 0; i <= 105; i++) En.m[i][i] = 1;
	while(scanf("%d %d %d", &n, &m, &k))
	{
		if (n == 0 && m == 0 && k == 0) break;
		En.row = En.col = n+1;
		M = En;
		char ch[5];
		int x, y;
		for (int i = 0; i < k; i++){
			scanf("%s", ch);
			if (ch[0] == 'g'){
				scanf("%d", &x);
				En.m[x-1][n] ++;
				M = En * M;
				En.m[x-1][n] --;
			}
			if (ch[0] == 'e'){
				scanf("%d", &x);
				En.m[x-1][x-1] --;
				M = En * M;
				En.m[x-1][x-1] ++;
			}
			if (ch[0] == 's'){
				scanf("%d %d", &x, &y);
				En.m[x-1][x-1] --;
				En.m[y-1][y-1] --;
				En.m[x-1][y-1] ++;
				En.m[y-1][x-1] ++;
				M = En * M;
				En.m[x-1][x-1] ++;
				En.m[y-1][y-1] ++;
				En.m[x-1][y-1] --;
				En.m[y-1][x-1] --;
			}
		}
		M = pow(M, m);
		for (int i = 0; i < n; i++)
			printf("%lld%c", M.m[i][n], i==n-1? '\n': ' ');
	}
	return 0;
}

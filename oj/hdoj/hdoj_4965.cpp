#pragma comment(linker, "/STACK:1024000000,1024000000")  
#include<cstdio>
#include<cstring>
using namespace std;

struct mat{
	int row, col;
	int m[1010][1010];
	void clear()
	{
		row = col = 0;
		memset(m, 0, sizeof(m));
	}
	void operator =(const mat &p){
		row = p.row;
		col = p.col;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				m[i][j] = p.m[i][j];
	}
	mat operator *(const mat &p);
} a, b, c, tmp, sum, ans;

mat mat::operator *(const mat &p){
	ans.row = row;
	ans.col = p.col;
	for (int i = 0; i < ans.row; i++)
		for (int j = 0; j < ans.col; j++)
			ans.m[i][j] = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (m[i][j]){
				for (int k = 0; k < p.col; k++)
					ans.m[i][k] += m[i][j] * p.m[j][k];
			}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < p.col; j++)
			ans.m[i][j] %= 6;
	return ans;
}

void print(const mat &tmp)
{
	for (int i = 0; i < tmp.row; i++)
		for (int j = 0; j < tmp.col; j++)
			printf("%d%c", tmp.m[i][j], j == tmp.col-1? '\n': ' ');
}

int n, k;
int main()
{
	while(scanf("%d %d", &n, &k) && n != 0 && k != 0)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < k; j++)
				scanf("%d", &a.m[i][j]);
		for (int i = 0; i < k; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &b.m[i][j]);
		a.row = n, a.col = k;
		b.row = k, b.col = n;
		tmp = b * a;
	//	print(tmp);
		sum.row = sum.col = tmp.row;
		for (int i = 0; i < sum.row; i++)
			for (int j = 0; j < sum.col; j++)
				sum.m[i][j] = 0;
		for (int i = 0; i < sum.row; i++)
			sum.m[i][i] = 1;
		//tmp = mat_powmod(tmp, n*n-1, 6);
		int exp = n * n - 1;
		while(exp){
			if (exp & 1) sum = sum * tmp;
			exp >>= 1;
			tmp = tmp * tmp;
		}
		c = a * sum * b;
		int ans = 0;
		for (int i = 0; i < c.row; i++)
			for (int j = 0; j < c.col; j++)
				ans += c.m[i][j];
		printf("%d\n", ans);
	}
	return 0;
}

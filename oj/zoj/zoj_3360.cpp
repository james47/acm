#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T;
int a, b;
int ans[100];
int dfs(int dep, int lim, int cura, int curb)
{
	if (cura == 0) return dep;
	if (dep == lim) return 0; 
	int l = max(curb/(2*cura) - 1, 2), r = curb/cura;
	for (int i = l; i <= r; i++){
		ans[dep] = i;
		int newa = curb - cura * i, newb = curb;
		int tmp = __gcd(newa, newb);
		newa /= tmp; newb /= tmp;
		tmp = dfs(dep+1, lim, newa, newb);
		if (tmp) return tmp;
	}
	return 0;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &a, &b);
		int gcd = __gcd(a, b);
		a /= gcd; b /= gcd;
		if (a > b - a) a = b - a;
		int lim, size;
		for (lim = 1; lim < 6; lim ++){
			size = dfs(0, lim, a, b);
			if (size) break;
		}
		if (lim == 6){
			puts("Too complex");
			continue;
		}
		else{
			for (int i = 0; i < size; i++)
				printf("%d%c", ans[i], i+1==size? '\n': ' ');
		}
	}
	return 0;
}

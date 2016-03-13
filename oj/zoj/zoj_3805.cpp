#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<ctime>
#include<string>
using namespace std;

int son[10100][2];
int n, x;
int f(int x)
{
	if (son[x][0] == 0 && son[x][1] == 0) return 1;
	if (son[x][1] == 0) return f(son[x][0]);
	int t1 = f(son[x][0]),
	    t2 = f(son[x][1]);
	if (t1 > t2) swap(t1, t2);
	return max(t1+1, t2);
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		memset(son, 0, sizeof(son));
		for (int i = 2; i <= n; i++){
			scanf("%d", &x);
			if (son[x][0] == 0) son[x][0] = i;
			else son[x][1] = i;
		}
		printf("%d\n", f(1));
	}
	return 0;
}


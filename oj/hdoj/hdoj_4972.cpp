#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T, n;
int main()
{
	scanf("%d", &T);
	int cas = 0;
	while(T--)
	{
		scanf("%d", &n);
		bool flag = false;
		int p = 0, t = 0, cnt = 0;
		for (int i = 0; i < n; i++){
			p = t;
			scanf("%d", &t);
			int del = abs(p-t);
			if ((del > 3) || (del == 0 && p != 1)) flag = true;
			if ((p == 1 && t == 2) || (p == 2 && t == 1)) cnt ++;
		}
		int ans = cnt;
		if (t == 0) ans = cnt + 1;
		else ans = 2 * cnt + 2;
		if (flag) ans = 0;
		printf("Case #%d: %d\n", ++cas, ans);
	}
	return 0;
}

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

const long long inf = int(1e5);
int n;
char ch;
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		getchar();
		long long ans = 1, tmp;
		int cnt = 0;
		bool flag = false;
		while(cnt < n){
			ch = getchar();
			if (ch == '\n') cnt ++;
			else {if (ch == '{'){
				tmp = 0;
				ch = getchar();
				while(ch != '}'){
					if (ch == '\n')	cnt++;
					if (ch == '|') tmp++;
					ch = getchar();
				}
				if (tmp > inf) flag = true;
				if (!flag) ans *= (tmp+1);
				if (ans > inf) flag = true;
			}
			else if (ch == '$'){
				tmp = 0;
				ch = getchar();
				while(ch != '$'){
					if (ch == '\n') cnt ++;
					else if (ch != ' '){
						if (tmp > inf) flag = true;
						if (!flag) ans *= (tmp+1);
						if (ans > inf) flag = true;
						tmp = 0;
					}
					else tmp ++;
					ch = getchar();
				}
				if (tmp > inf) flag = true;
				if (!flag) ans *= (tmp+1);
				if (ans > inf) flag = true;
			}
			}
		}
		if (flag) printf("doge\n");
		//else printf("%I64d\n", ans);
		else printf("%lld\n", ans);
	}
	return 0;
}

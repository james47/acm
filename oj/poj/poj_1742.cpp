#include<cstdio>
#include<cstring>
using namespace std;

int n, m, head, tail;
int a[150], c[150];
int q[(int)1e5+100];
bool dp[(int)1e5+100];
int main()
{
	while(scanf("%d %d", &n, &m) && (n+m))
	{
		for (int i = 0; i < n; i++)
			scanf("%d", a+i);
		for (int i = 0; i < n; i++)
			scanf("%d", c+i);
		memset(dp, 0, sizeof(dp));
		dp[0] = true;
		for (int i = 0; i < n; i++){
			int maxl = a[i] * c[i];
			if (c[i] == 1){
				for (int j = m; j >= a[i]; j--)
					if (dp[j - a[i]]) dp[j] = true; 
			}
			else if (m <= maxl){
				for (int j = a[i]; j <= m; j++)
					if (dp[j - a[i]]) dp[j] = true; 
			}
			else for (int j = 0; j < a[i]; j++){
				head = tail = 0;
				for (int k = j; k <= m; k += a[i]){
					while (head != tail && k - q[head] > maxl) head++;
					if (!dp[k]){
						if (head != tail) 
							dp[k] = true;
					}
					else q[tail++] = k;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= m; i ++)
			if (dp[i]) ans ++;
		printf("%d\n", ans);
	}
	return 0;
}

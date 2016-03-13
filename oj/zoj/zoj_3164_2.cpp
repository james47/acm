#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1500;
int N, D, G, oo;
int flag[maxn], k[maxn], e[maxn], p[maxn], tmp[maxn], dp[maxn];
int w[10][maxn];
char str[100000];
void complete(int w, int v, int dp[])
{
	for (int i = w; i <= D; i++)
		if (dp[i-w] != -oo)
			dp[i] = max(dp[i], dp[i-w] + v);
}
void zero_one(int w, int v, int dp[])
{
	for (int i = D; i >= w; i--)
		if (dp[i-w] != -oo)
			dp[i] = max(dp[i], dp[i-w] + v);
}
int main()
{
	while(scanf("%d %d", &N, &D) != EOF)
	{
		for (int i = 1; i <= N; i++)
			scanf("%d %d %d", k+i, e+i, p+i);
		scanf("%d", &G); getchar();
		memset(flag, 0, sizeof(flag));
		for (int i = 1; i <= G; i++){
			gets(str);
			int len = strlen(str);
			for (int j = 0; j < len;){
				if (str[j] >= '1' && str[j] <= '9'){
					int sum = 0;
					while (str[j] >= '0' && str[j] <= '9'){
						sum = sum * 10 + str[j] - '0';
						j++;
					}
					flag[sum] = i;
				}
				else j++;
			}
		}
		memset(dp, 128, sizeof(dp));
		oo = -dp[0];
		dp[0] = 0;
		for (int i = 1; i <= G; i++){
			memset(w[i], 128, sizeof(w[i]));
			w[i][0] = 0;
		}
		for (int i = 1; i <= N; i++){
			if (flag[i]){
				memset(tmp, 128, sizeof(tmp));
				tmp[0] = 0;
			}
			if (k[i] == 0 || k[i] * p[i] >= D)
				complete(p[i], e[i], flag[i] ? tmp : dp);
			else {
				int t = 1, cnt = k[i];
				while(t < cnt){
					zero_one(t * p[i], t * e[i], flag[i] ? tmp : dp);
					cnt -= t;
					t <<= 1;
				}
				zero_one(cnt * p[i], cnt * e[i], flag[i] ? tmp : dp);
			}
			if (flag[i]) for (int j = 0; j <= D; j++) w[flag[i]][j] = max(w[flag[i]][j], tmp[j]);
		}
		for (int i = 1; i <= G; i++)
			for (int v = D; v >= 0; v--)
				for (int j = 0; j <= v; j++)
					if (dp[v-j] != -oo && w[i][j] != -oo){
						dp[v] = max(dp[v], dp[v-j] + w[i][j]);
					}
		if (dp[D] >= 0) printf("%d\n", dp[D]);
		else printf("i'm sorry...\n");
	}
	return 0;
}


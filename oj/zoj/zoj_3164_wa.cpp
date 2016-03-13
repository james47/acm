#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct que{
	int v, p;
} q[1500];
int n, d, G, oo, head, tail;
int k[1500], e[1500], p[1500];
int dp[1500][10];
bool ingroup[1500];
char str[100000];
vector<int> g[10];
int in(int &pos)
{
	int ans = 0, len = strlen(str);
	while(pos < len && !('0' <= str[pos] && str[pos] <= '9')) pos ++;
	if (pos == len) return 0;
	while(pos < len && ('0' <= str[pos] && str[pos] <= '9')){
		ans = ans * 10 + str[pos] - '0';
		pos ++;
	}
	return ans;
}
int main()
{
	while(scanf("%d%d", &n, &d) != EOF)
	{
		for (int i = 1; i <= n; i ++)
			scanf("%d%d%d", k+i, e+i, p+i);
		scanf("%d", &G);
		memset(ingroup, false, sizeof(ingroup));
		if (G) getchar(); 
		for (int i = 1; i <= G; i++){
			g[i].clear();
			gets(str);
			int pos = 0;
			int id = in(pos);
			while (id != 0){
				ingroup[id] = true;
				g[i].push_back(id);
				id = in(pos);
			}
		}
		memset(dp, 128, sizeof(dp));
		oo = -dp[0][0];
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++){
			if (ingroup[i]) continue;
			if (k[i] == 0 || p[i] * k[i] > d){
				for (int j = p[i]; j <= d; j++)
					if (dp[j-p[i]][0] != -oo)
						dp[j][0] = max(dp[j-p[i]][0] + e[i], dp[j][0]);
			}
			else if (k[i] == 1){
				for (int j = d; j >= p[i]; j--)
					if (dp[j-p[i]][0] != -oo)
						dp[j][0] = max(dp[j-p[i]][0] + e[i], dp[j][0]);
			}
			else{
				int maxl = p[i] * k[i];
				for (int j = 0; j < p[i]; j++){
					head = tail = 0;
					for (int k = j, cnt = 0; k <= d; k += p[i], cnt++){
						while(head != tail && k - q[head].p > maxl) head++;
						if (dp[k][0] != -oo){
							int tmp = dp[k][0] - cnt * e[i];
							while(head != tail && q[tail-1].v < tmp) tail --;
							q[tail].p = k; q[tail++].v = tmp;
						}
						if (head != tail)
							dp[k][0] = max(q[head].v + cnt * e[i], dp[k][0]);
					}
				}
			}
		}
		for (int gi = 1; gi <= G; gi++){
			for (int t = 0; t < g[gi].size(); t++){
				int i = g[gi][t];
				if (k[i] == 1){
					for (int j = d; j >= p[i]; j--)
						if (dp[j-p[i]][gi-1] != -oo)
							dp[j][gi] = max(dp[j-p[i]][gi-1] + e[i], dp[j][gi]);
				}
				else{
					int maxl = p[i] * k[i];
					if (k[i] == 0) maxl = 2 * d;
					for (int j = 0; j < p[i]; j++){
						head = tail = 0;
						for (int k = j, cnt = 0; k <= d; k += p[i], cnt++){
							while(head != tail && k - q[head].p > maxl) head++;
							if (dp[k][gi-1] != -oo){
								int tmp = dp[k][gi-1] - cnt * e[i];
								while(head != tail && q[tail-1].v < tmp) tail --;
								q[tail].p = k; q[tail++].v = tmp;
							}
							if (head != tail)
								dp[k][gi] = max(q[head].v + cnt * e[i], dp[k][gi]);
						}
					}
				}
			}
		}
		int ans = -oo;
		for (int i = 0; i <= G; i++)
			if (dp[d][i] > ans) ans = dp[d][i];
		if (ans >= 0) printf("%d\n", ans);
		else printf("i'm sorry...\n");
	}
	return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m, k;
int a[120][10100], b[120][10100], dp[120][10100];
struct que{
	int v, d;
} q[10100];
inline int in(){
	char ch = getchar();
	while((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	bool flag = false;
	if (ch == '-'){
		flag = true;
		ch = getchar();
	}
	int ans = 0;
	while(ch >= '0' && ch <= '9'){
		ans = ans*10 + ch-'0';
		ch = getchar();
	}
	if (flag) return -ans;
	return ans;
}
int main()
{
	while(scanf("%d%d%d", &n, &m, &k) && (n+m+k))
	{
		for (int i = 0; i <= n; i++)
			for (int j = 0; j < m; j++)
				a[i][j] = in();
		for (int i = 0; i <= n; i++)
			for (int j = 0; j < m; j++)
				b[i][j] = in();
		for (int j = 0; j <= m; j++)
			dp[n+1][j] = 0;
		for (int i = n; i >= 0; i--){
			int sum, head, tail, dis;
			sum = head = tail = dis = 0;
			dp[i][0] = dp[i+1][0];
			q[tail].v = dp[i][0];
			q[tail++].d = 0;
			for (int j = 1; j <= m; j++){
				sum += a[i][j-1];
				dis += b[i][j-1];
				while(head < tail && dis - q[head].d > k) head ++;
				while(head < tail && q[tail-1].v <= dp[i+1][j] - sum) tail --;
				q[tail].d = dis;
				q[tail++].v = dp[i+1][j] - sum;
				dp[i][j] = q[head].v + sum;
			}
			sum = head = tail = dis = 0;
			q[tail].v = dp[i+1][m];
			q[tail++].d = 0;
			for (int j = m-1; j >= 0; j--){
				sum += a[i][j];
				dis += b[i][j];
				while(head < tail && dis - q[head].d > k) head ++;
				while(head < tail && q[tail-1].v <= dp[i+1][j] - sum) tail --;
				q[tail].d = dis;
				q[tail++].v = dp[i+1][j] - sum;
				if (q[head].v + sum > dp[i][j]) dp[i][j] = q[head].v + sum;
			}
		}
		int ans = 0;
		for (int i = 0; i <= m; i++)
			if (dp[0][i] > ans) ans = dp[0][i];
		printf("%d\n", ans);
	}
	return 0;
}

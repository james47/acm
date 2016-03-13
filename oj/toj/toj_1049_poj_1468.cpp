#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int l[30000], r[30000], u[30000], d[30000];
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++) scanf("%d %d %d %d", l+i, r+i, d+i, u+i);
		int ans = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i == j) continue;
				if (l[j] <= l[i] && r[i] <= r[j] && d[j] <= d[i] && u[i] <= u[j]){
					ans ++;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

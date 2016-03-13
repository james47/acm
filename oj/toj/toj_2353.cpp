#include<cstdio>
#include<cstring>
using namespace std;

int T, n;
int a[400], id[400];
bool vis[400];
int main()
{
	scanf("%d", &T);
	memset(vis, 0, sizeof(vis));
	while(T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%d", a+i);
		}
		for (int i = n;;i++){
			bool flag = true;
			for (int j = 0; j < n; j++){
				id[j] = a[j] % i;
				if (vis[id[j]]){
					for (int k = 0; k < j; k++) vis[id[k]] = false;
					flag = false;
					break;
				}
				else vis[id[j]] = true;
			}
			if (flag) printf("%d\n", i);
			for (int j = 0; j < n; j++) vis[id[j]] = false;
			if (flag) break;
		}
	}
	return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m, x, y;
int main()
{
	while(scanf("%d %d %d %d", &n, &m, &x, &y) != EOF){
		if ((n&1) && n == m && x == y && x == (n+1)/2){
			printf("%d\n", n/2);
			continue;
		}
		if (n > m){
			swap(n, m);
			swap(x, y);
		}
		int ans = (n+1)/2;
		if ((x == 1 || x == n) && (y == 1 || y == m)){
			printf("%d\n", ans);
			continue;
		}
		int h = max(x-1, n-x), w = min(y, m-y+1);

		//***
		if (n&1){
			if (x+x-1 != n) if (w > ans) ans = min(h, w);
		}
		else{
			if ((n/2 != x) && (n/2 != x-1)) if (w > ans) ans = min(h, w);
		}
		/* codes starting from *** are equal to codes below
		if (w > ans && x-1 != n-x){
			ans = min(h, w);
		}
		*/
		printf("%d\n", ans);
	}
	return 0;
}

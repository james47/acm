#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int T, n, m;
int a[30], b[30];
int lcm(int a, int b){ return a / __gcd(a, b) * b; }
bool ok(int x){
	int tmp;
	for (int i = 0; i < m; i++){
		tmp = x % a[i];
		if (tmp != b[i]) return false;
	}
	return true;
}

int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &n, &m);
		int lim = 1;
		for (int i = 0; i < m; i++) {scanf("%d", a+i); lim = lcm(lim, a[i]);};
		for (int i = 0; i < m; i++) scanf("%d", b+i);
		int ans = 0;
		for (int i = 1; i <= lim && i <= n; i++){
			if (ok(i)){
				//printf("%d\n", (n-1)/lim + (i%lim<=n%lim));
				//ans = (n-i)/lim + 1; //AC
				//printf("%d\n", ans);
				ans = (n-1)/lim + (i <= (n%lim==0?lim:n%lim));
				//printf("%d\n", ans);
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

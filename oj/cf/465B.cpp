#include<cstdio>
#include<cstring>
using namespace std;

int n, x;
int main()
{
	scanf("%d", &n);
	int ans = 0, pre = 0, first = 1;
	while(n--){
		scanf("%d", &x);
		if (x == 1){
			if (first){
				ans ++;
				first = 0;
			}
			else{
				if (pre == 0) ans += 2;
				else ans ++;
			}
		}
		pre = x;
	}
	printf("%d\n", ans);
	return 0;
}

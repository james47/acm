#include<cstdio>
using namespace std;

int main()
{
	int n, a, b, x;
	while(scanf("%d", &n) != EOF){
		a = b = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &x);
			if (x == 100) a++; else b++;
		}
		if (a & 1){
			printf("NO\n");
			continue;
		}
		int t;
		x = t = a / 2 + b;
		while(t > 1 && b) t -= 2, b--;
		while(t && a) t--, a--;
		if (a + b * 2 == x) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

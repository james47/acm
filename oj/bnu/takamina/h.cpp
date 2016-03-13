#include<cstdio>
#include<cstring>
using namespace std;

int n;
int main()
{
	scanf("%d", &n);
	if (n < 4) puts("NO");
	else{
		puts("YES");
		if (n & 1){
			int cnt = 0;
			for (int i = n; i > 5; i -= 2){
				printf("%d - %d = 1\n", i, i-1);
				cnt++;
			}
			for (int i = 1; i < cnt; i++) printf("1 * 1 = 1\n");
			printf("2 + 5 = 7\n");
			printf("3 * 7 = 21\n");
			printf("21 + 4 = 25\n");
			printf("25 - 1 = 24\n");
			if (cnt) printf("24 * 1 = 24\n");
		}
		else{
			int cnt = 0;
			for (int i = n; i > 4; i -= 2){
				printf("%d - %d = 1\n", i, i-1);
				cnt++;
			}
			for (int i = 1; i < cnt; i++) printf("1 * 1 = 1\n");
			printf("1 * 2 = 2\n");
			printf("2 * 3 = 6\n");
			printf("6 * 4 = 24\n");
			if (cnt) printf("24 * 1 = 24\n");
		}
	}
	return 0;
}

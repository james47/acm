#include<cstdio>
using namespace std;

int col[3];
int main()
{
	while(scanf("%d %d %d", &col[0], &col[1], &col[2]) != EOF)
	{
		int cnt = 0;
		for (int i = 0; i < 3; i++)
			if (col[i] >= 2){
				cnt += 2;
				col[i] -= 2;
			}
			else if (col[i] >= 1){
				cnt += 1;
				col[i] -= 1;
			}
		long long ans = 0;
		for (int i = 1; i < cnt; i++)
			ans += i;
		for (int i = 0; i < 3; i++)
			ans += (long long) col[i] * cnt;
		printf("%I64d\n", ans);
	}
	return 0;
}

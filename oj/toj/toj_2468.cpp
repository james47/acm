#include<cstdio>
#include<cstring>
using namespace std;

char str[300];
int cnt[30];
int T;
int main()
{
	scanf("%d", &T);
	getchar();
	memset(cnt, 0, sizeof(cnt));
	while(T--)
	{
		gets(str);
		int len = strlen(str);
		for (int i = 0; i < len; i++)
			if (str[i] >= 'a' && str[i] <= 'z') cnt[str[i]-'a']++;
		int maxcnt = 0;
		for (int i = 0; i < 26; i++)
			if (cnt[i] > maxcnt) maxcnt = cnt[i];
		for (int i = 0; i < 26; i++){
			if (cnt[i] == maxcnt) printf("%c", i + 'a');
			cnt[i] = 0;
		}
		printf("\n");
	}
	return 0;
}

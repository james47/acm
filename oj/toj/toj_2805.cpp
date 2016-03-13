#include<cstdio>
#include<cstring>
using namespace std;

int n;
int l[30];
char str[60000];
void init()
{
	l[0] = 1;
	for (int i = 1; i <= 10; i++) l[i] = l[i-1] * 3;
	str[0] = '@';
	for (int i = 1; i <= 10; i++){
		int len = l[i-1];
		for (int j = len; j < len * 2; j++)
			str[j] = ' ';
		for (int j = len * 2, k = 0; j < len * 3; j++, k++)
			str[j] = str[k];
	}
}
int main()
{
	init();
	while(scanf("%d", &n) != EOF){
		char ch = str[l[n]];
		str[l[n]] = '\0';
		printf("%s\n", str);
		str[l[n]] = ch;
	}
	return 0;
}

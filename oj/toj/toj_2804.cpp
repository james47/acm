#include<cstdio>
#include<cstring>
using namespace std;

char str[1500];
int a[1500];
int main()
{
	while(scanf("%s", str) != EOF){
		int l = strlen(str);
		for (int i = 0; i < l; i++) a[i] = str[i] - '0';
		for (int i = 0; i < l-1; i++){
			a[i+1] = a[i+1] + (a[i] % 3) * 10;
			a[i] = a[i] / 3;
		}
		a[l-1] = a[l-1]/3;
		int i;
		for (i = 0; a[i] == 0; i++);
		for (; i < l-1; i++) printf("%d", a[i]);
		printf("%d\n", a[l-1]);
	}
	return 0;
}

#include<cstdio>
#include<cstring>
using namespace std;

char s[300];
double x, y;
int main()
{
	while (scanf("%s", s) != EOF)
	{
		printf("%s [8] = ", s);
		x = 0; y = 1;
		for (int i = strlen(s)-1; i > 1; i--){
			x = (x + y * (s[i]-'0')) * 125;
			y *= 1000;
		}
		x /= y;
		int p = 0;
		while (x){
			x *= 10;
			s[p] = int(x) % 10 + '0';
			x -= s[p] - '0';
			p++;
		}
		s[p] = '\0';
		printf("0.%s [10]\n", s);
	}
	return 0;
}

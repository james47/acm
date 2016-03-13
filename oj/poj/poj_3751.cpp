#include<cstdio>
using namespace std;

int T;
int y, m, d, h, mi, s;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d/%d/%d-%d:%d:%d", &y, &m, &d, &h, &mi, &s);
		char ch;
		if (h >= 12) ch = 'p';
		else ch = 'a';
		if (h == 0) h = 12;
		if (h > 12) h -= 12;
		printf("%02d/%02d/%04d-%02d:%02d:%02d%cm\n", m, d, y, h, mi, s, ch);
	}
	return 0;
}

#include<cstdio>
using namespace std;

int read()
{
	int ret = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret;
}
int f91(int x)
{
	if (x <= 100) return f91(f91(x+11));
	else return x-10;
}
int main()
{
	while(1)
	{
		int n = read();
		if (n == 0) break;
		printf("f91(%d) = %d\n", n, f91(n));
	}
	return 0;
}

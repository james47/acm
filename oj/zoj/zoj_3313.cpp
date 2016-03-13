#include<stdio.h>

int n, T;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		printf("%.2f\n", 480.0 * n);
	}
	return 0;
}

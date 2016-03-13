#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	printf("10\n");
	for (int t = 0; t < 10; t++){
		int n = rand() % 20 + 1;
		int D = rand() % 50;
		printf("%d %d\n", n, D);
		for (int i = 0; i < n; i++){
			int w = rand() % D + 1;
			printf("%d ", w);
		}
		printf("\n");
	}
	return 0;
}

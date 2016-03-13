#include<cstdio>
#include<cstring>
using namespace std;

int n;
int a[110][110];
int row[110], col[110];
int main()
{
	while(scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &a[i][j]);
		int rcnt = 0, ccnt = 0, rm, cm;
		for (int i = 0; i < n; i++){
			row[i] = 0;
			for (int j = 0; j < n; j++)
				if (a[i][j]) row[i]++;
			if (row[i] & 1){
				rcnt++;
				rm = i;
			}
		}
		for (int j = 0; j < n; j++){
			col[j] = 0;
			for (int i = 0; i < n; i++)
				if (a[i][j]) col[j] ++;
			if (col[j] & 1){
				ccnt++;
				cm = j;
			}
		}
		if (rcnt == 0 && ccnt == 0){
			puts("OK");
		}
		else if (rcnt == ccnt && rcnt == 1){
			printf("Change bit (%d,%d)\n", rm+1, cm+1);
		}
		else puts("Corrupt");
	}
	return 0;
}

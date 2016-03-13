#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<ctime>
#include<string>
using namespace std;

int T;
char aa[30], bb[30];
int a[20], b[20];
int abig[10], bbig[10], acnt[10], bcnt[10];
int trans(char x)
{
	if ('3' <= x && x <= '9') return x - '0' - 2;
	if (x == 'T') return 8;
	if (x == 'J') return 9;
	if (x == 'Q') return 10;
	if (x == 'K') return 11;
	if (x == 'A') return 12;
	if (x == '2') return 13;
	if (x == 'X') return 14;
	if (x == 'Y') return 15;
}
bool legal()
{
	memset(acnt, 0, sizeof(acnt));
	int sum = 0;
	for (int i = 1; i <= 15; i++)
		sum += a[i];
//	printf("%d\n", sum);
	if (sum > 6) return false;
	if (sum == 1) return true;
	for (int i = 1; i <= 15; i++){
		if (a[i]) acnt[a[i]]++;
	}
//	for (int i = 1; i <= 15; i++)
//		printf("%d ", a[i]);
//	printf("\n");
//	for (int i = 1; i <= 6; i++)
//		printf("%d ", acnt[i]);
//	printf("\n");
	if (sum == 2 && acnt[2]) return true;
	if (sum == 3 && acnt[3]) return true;
	if (sum == 4 && acnt[4]) return true;
	if (sum == 4 && acnt[3]) return true;
	if (sum == 5 && acnt[3] && acnt[2]) return true;
	if (sum == 6 && acnt[4]) return true;
	return false;
}
bool comp()
{
	if (legal()) return 1;
	if (a[14] && a[15]) return 1;
	if (b[14] && b[15]) return 0;
	memset(abig, -1, sizeof(abig));
	memset(acnt, 0, sizeof(acnt));
	memset(bbig, -1, sizeof(bbig));
	memset(bcnt, 0, sizeof(bcnt));
	for (int i = 1; i <= 15; i++){
		if (a[i]){
			acnt[a[i]]++;
			for (int j = 1; j <= a[i]; j++)
				abig[j] = i;
		}
		if (b[i]){
			bcnt[b[i]]++;
			for (int j = 1; j <= b[i]; j++)
				bbig[j] = i;
		}
	}
	if (abig[4] > bbig[4]) return true;
	else if (bbig[4] != -1) return false;
	if (abig[1] > bbig[1]) return true;
	if (abig[2] > bbig[2]) return true;
	if (abig[3] > bbig[3]) return true;
	if (abig[3] != -1 && acnt[1] != 0 && bcnt[1] == 0 && bcnt[2] == 0) return true;
	if (abig[3] != -1 && acnt[2] != 0 && bcnt[2] == 0) return true;
	return false;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s %s", aa, bb);
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 0; i < strlen(aa); i++){
			int x = trans(aa[i]);
			a[x] ++;
		}
		for (int i = 0; i < strlen(bb); i++){
			int x = trans(bb[i]);
			b[x] ++;
		}
		bool win = comp();
		if (win) puts("Yes");
		else puts("No");
	}
	return 0;
}


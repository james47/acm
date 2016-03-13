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

char num[15][3][4] = {
{
"._.",
"|.|",
"|_|"
},
{
"...",
"..|",
"..|"
},
{
"._.",
"._|",
"|_."
},
{
"._.",
"._|",
"._|"
},
{
"...",
"|_|",
"..|"
},
{
"._.",
"|_.",
"._|"
},
{
"._.",
"|_.",
"|_|"
},
{
"._.",
"..|",
"..|"
},
{
"._.",
"|_|",
"|_|"
},
{
"._.",
"|_|",
"._|"
}
};
char a[15][3][4];
char str[5][60];
int digit[15];

void trans()
{
	int id;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 27; j++){
			id = j / 3;
			a[id][i][j%3] = str[i][j]; 
		}
	}
}
bool compare(char a[3][4], char b[3][4])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (a[i][j] != b[i][j]) return false;
	return true;
}
bool can(char a[3][4], char b[3][4])
{
	for (int i = 0; i < 3; i ++)
		for (int j = 0; j < 3; j++)
			if (a[i][j] != '.' && b[i][j] == '.') return false;
	return true;
}
int solve()
{
	int ret = 0, cnt = 0;
	for (int i = 0; i < 9; i++){
		bool flag = false;
		for (int j = 0; j < 10; j++)
			if (compare(a[i], num[j])){
					digit[i] = j;
					flag = true;
					break;
			}
		if (!flag){
			digit[i] = -1;
			cnt ++;
		}
	}
	//printf("%d\n", cnt);
	if (cnt >= 2) return 0;
	if (cnt == 1){
		int tmp = 0, pos;
		for (int i = 0; i < 9; i++){
			//printf("%d\n", digit[i]);
			if (digit[i] != -1) tmp = tmp + digit[i] * (9 - i);
			else pos = i;
		}
		int wrong = 0;
		for (int j = 0; j < 10; j++)
			if (can(a[pos], num[j])){
				int tmpp = tmp + j * (9 - pos);
				if (tmpp % 11 == 0){
					wrong++;
					if (wrong == 2) return wrong;
					digit[pos] = j;
				}
			}
		return wrong;
	}
	else{
		int tmp = 0;
		for (int i = 0; i < 9; i++)
			tmp = tmp + digit[i] * (9 - i);
		if (tmp % 11 == 0) ret ++;
		int ori[15];
		for (int i = 0; i < 9; i++) ori[i] = digit[i];
		for (int i = 0; i < 9; i++){
			tmp = 0;
			for (int j = 0; j < 9; j++) if (j != i) tmp = tmp + ori[j] * (9 - j);
			for (int j = 0; j < 10; j++){
				if (ori[i] != j && can(a[i], num[j])){
					int tmpp = tmp + j * (9 - i);
					if (tmpp % 11 == 0){
						ret ++;
						if (ret == 2) return ret;
						digit[i] = j;
					}
				}
			}
		}
	}
	return ret;
}
int main()
{
	while(gets(str[0]))
	{
		gets(str[1]);
		gets(str[2]);
		trans();
		int cnt = solve();
		if (cnt == 0) puts("failure");
		else if (cnt == 2) puts("ambiguous");
		else{
			for (int i = 0; i < 9; i++)
				printf("%d", digit[i]);
			printf("\n");
		}
	}
	return 0;
}

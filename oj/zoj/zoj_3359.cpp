#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T;
int home[50], away[50];
char tmp[10];
char win[2][10] = {"home", "away"};
void output(int cas, int winner, int sh, int sa)
{
	printf("Match %d:\n", cas);
	printf("Winner: %s\n", win[winner]);
	printf("Score: %d:%d\n", sh, sa);
}
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		int sh, sa, winner;
		bool flag = false;
		for (int i = 1; i <= 11; i++){
			for (int j = 0; j < 3; j++){
				scanf("%s", tmp);
				if (tmp[0] == 'y'){
					home[i+j*11] = 1;
				}
				else home[i+j*11] = 0;
			}
		}
		for (int i = 1; i <= 11; i++){
			for (int j = 0; j < 3; j++){
				scanf("%s", tmp);
				if (tmp[0] == 'y'){
					away[i+j*11] = 1;
				}
				else away[i+j*11] = 0;
			}
		}
		sh = sa = 0;
		for (int i = 1; i <= 5; i++){
			sh += home[i];
			if (sh - sa > 5 - i + 1){
				winner = 0;
				flag = true;
				break;
			}
			if (sa - sh > 5 - i){
				winner = 1;
				flag = true;
				break;
			}
			sa += away[i];
			if (sh - sa > 5 - i){
				winner = 0;
				flag = true;
				break;
			}
			if (sa - sh > 5 - i){
				winner = 1;
				flag = true;
				break;
			}
		}
		if (flag){
			output(cas, winner, sh, sa);
			continue;
		}
		for (int i = 6; i <= 33; i++){
			sh += home[i];
			sa += away[i];
			if (sh > sa){
				winner = 0;
				break;
			}
			if (sa > sh){
				winner = 1;
				break;
			}
		}
		output(cas, winner, sh, sa);
	}
	return 0;
}

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

struct node{
	int id, ct, score;
} ss[1100];
int n, s, p;
int pct[1100];
int so[1100][1100];
bool cmp(node a, node b)
{
	if (a.score == b.score && a.ct == b.ct) return a.id < b.id;
	if (a.score == b.score) return a.ct > b.ct;
	return a.score > b.score;
}
int main()
{
	while(scanf("%d %d %d", &n, &s, &p) != EOF)
	{
		memset(pct, 0, sizeof(pct));
		memset(ss, 0, sizeof(ss));
		for (int i = 0; i <= s; i++) ss[i].id = i;
		for (int i = 0; i < n; i++){
			for (int j = 1; j <= s; j++){
				scanf("%d", &so[j][i]);
				if (so[j][i] == 1){
					pct[i] ++;
					ss[j].ct ++;
				}
			}
		}
		for (int i = 1; i <= s; i++){
			for (int j = 0; j < n; j++)
				if (so[i][j]) ss[i].score += s - pct[j];
		}
		sort(ss+1, ss+s+1, cmp);
		int rank;
		for (rank = 1; rank <= s; rank++)
			if (ss[rank].id == p) break;
		printf("%d %d\n", ss[rank].score, rank);
	}
	return 0;
}


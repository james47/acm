/*************************************************************************
    > File Name: poj_2001.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sun Jul 19 09:48:16 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct ss{
	int len;
	char s[26];
} s[10010];
struct tree{
	int nex[26], son[26];
	void init(){
		memset(son, 0, sizeof(son));
		memset(nex, 0, sizeof(nex));
	}
} t[110000];

int T, size, n;
void insert(int x){
	int id = 0, di;
	for (int i = 0; i < s[x].len; i++){
		di = s[x].s[i] - 'a';
		t[id].son[di]++;
		if (t[id].nex[di]){
			id = t[id].nex[di];
		}
		else{
			t[id].nex[di] = size;
			id = size;
			t[size++].init();
		}
	}
}
void work(int x){
	int id = 0, di;
	for (int i = 0; i < s[x].len; i++){
		di = s[x].s[i] - 'a';
		if (t[id].son[di] <= 1){
			printf("%s ", s[x].s);
			s[x].s[i+1] = 0;
			printf("%s\n", s[x].s);
			return;
		}
		id = t[id].nex[di];
	}
	printf("%s %s\n", s[x].s, s[x].s);
}
int main()
{
	int n = 0;
	size = 1; t[0].init();
	while(scanf("%s", s[n].s) != EOF){
		s[n].len = strlen(s[n].s);
		insert(n);
		n ++;
	}
	for (int i = 0; i < n; i++) work(i);
	return 0;
}

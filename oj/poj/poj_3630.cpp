/*************************************************************************
    > File Name: poj_3630.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sun Jul 19 09:09:08 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct ss{
	int len;
	char s[11];
} s[10010];
struct tree{
	int nex[11];
	bool is;
	void init(){
		is = false;
		memset(nex, 0, sizeof(nex));
	}
} t[110000];
int T, size, n;
bool cmp(ss a, ss b){
	return a.len < b.len;

/*
	for (int i = 0; i < la; i++)
		if (a[i] < b[i]) return true;
		else if (a[i] > b[i]) return false;
	if (la <= lb) return true;
	if (la > lb) return false;
*/
}
bool flag;
bool insert(int x){
	int id = 0, di;
	for (int i = 0; i < s[x].len; i++){
		di = s[x].s[i] - '0';
		if (t[id].nex[di]){
			id = t[id].nex[di];
			if (t[id].is) return false;
		}
		else{
			t[id].nex[di] = size;
			id = size;
			t[size++].init();
		}
		//printf("%s %d %d\n", s[x].s, i, id);
	}
	t[id].is = true;
	return true;
}
int main()
{
	scanf("%d", &T);
	while(T--){
		size = 1; flag = true;
		for (int i = 0; i < 10; i++) t[0].nex[i] = 0;
		t[0].is = false;
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%s", s[i].s);
			s[i].len = strlen(s[i].s);
		}
		sort(s, s+n, cmp);
		for (int i = 0; i < n; i++){
			flag = insert(i);
			if (!flag) break;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}

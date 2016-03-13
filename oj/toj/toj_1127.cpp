#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

struct node{
	char s[60];
	int measure;
} a[110];
int n, m;
bool cmp(node a, node b)
{
//	printf("%s %s\n", a.s, b.s);
	return a.measure < b.measure;
}
int cal(int x)
{
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++){
			if (a[x].s[i] > a[x].s[j]) ret++;
		}
	return ret;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++){
		scanf("%s", a[i].s);
		a[i].measure = cal(i);
	}
	sort(a, a+m, cmp);
	for (int i = 0; i < m; i++)
		printf("%s\n", a[i].s);
	return 0;
}

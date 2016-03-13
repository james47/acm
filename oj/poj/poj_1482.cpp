#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxq = (1<<20) + 10;
int q[(1<<20)+15];
int n, m, maxn, oo, w[110];
int f[(1<<20)+10], ha[(1<<20)+10];
int cas = 0;
char s1[30], s2[30];
bool in[(1<<20)+10];
int pre[110][2], fixed[110][2];
void cook_the_raw(int i)
{
	pre[i][0] = pre[i][1] = fixed[i][1] = 0;
	fixed[i][0] = maxn;
	for (int j = 0; j < n; j++){
		if (s1[j] == '+') pre[i][1] += 1 << j;
		else if (s1[j] == '-') pre[i][0] += 1 << j;
		if (s2[j] == '+') fixed[i][1] += 1 << j;
		else if (s2[j] == '-') fixed[i][0] -= 1 << j;
	}
}
void init()
{
	cas ++;
	maxn = (1 << n) - 1;
	f[maxn] = 0; ha[maxn] = cas;
	for (int i = 0; i < m; i++){
		scanf("%d %s %s", &w[i], s1, s2);
		cook_the_raw(i);
	}
}
void spfa()
{
	int head, tail;
	head = tail = 0;
	q[tail++] = maxn;
	in[maxn] = true;
	while (head != tail)
	{
		int u = q[head++];
		if (head == maxq) head = 0;
		for (int i = 0; i < m; i++){
			if (((u & pre[i][1]) == pre[i][1]) && ((u & pre[i][0]) == 0)){
				int v = (u | fixed[i][1]) & fixed[i][0];
				if (ha[v] != cas || f[v] > f[u] + w[i]){
					f[v] = f[u] + w[i]; ha[v] = cas;
					if  (!in[v]){
						q[tail++] = v;
						if (tail == maxq) tail = 0;
						in[v] = true;
					}
				}
			}
		}
		in[u] = false;
	}
}
void print()
{
	printf("Product %d\n", cas); 
	if (ha[0] != cas) printf("Bugs cannot be fixed.\n\n");
	else printf("Fastest sequence takes %d seconds.\n\n", f[0]);
}
int main()
{
	memset(in, false, sizeof(in));
	memset(ha, 0, sizeof(ha));
	while(scanf("%d %d", &n, &m) && n+m)
	{
		init();
		spfa();
		print();
	}
	return 0;
}

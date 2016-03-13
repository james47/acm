#include<cstdio>
#include<cstring>
using namespace std;

const int mo = 10000007;
char str[110];
int n, numofpt, numofchain, tot;
bool flag;
int in[110], ch[110];
long long c[110][110], d[110];
void init()
{
	memset(c, 0, sizeof(c));
	c[0][0] = 1;
	for (int i = 1; i <= 100; i++)
		for (int j = 0; j <= i; j++)
			if (i == j || j == 0) c[i][j] = 1;
			else c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mo;
	d[0] = 1;
	d[1] = 0;
	for (int i = 2; i <= 100; i++)
		d[i] = (d[i-1] + d[i-2]) * (i-1) % mo;
}
void read()
{
	memset(in, 0, sizeof(in));
	memset(ch, 0, sizeof(ch));
	for (int i = 0; i < n; i++){
		scanf("%s", str);
		for (int j = 0; j < n; j++)
			if (str[j] == 'Y') ch[i]++, in[j]++;
	}
	numofpt = tot = numofchain = 0;
	flag = false;
	for (int i = 0; i < n; i++){
		if (in[i] > 1 || ch[i] > 1){
			flag = true;
			break;
		}
		if (in[i] == 0){
			tot ++;
			if (ch[i] == 0) numofpt ++;
		}
	}
	numofchain = tot - numofpt;
}
void solve()
{		
	if (flag){
		puts("0");
		return;
	}
	else{
		long long ans = 0;
		for (int i = 0; i <= numofchain; i++){
			ans = (ans + c[numofchain][i] * d[i + numofpt]) % mo;
		}
		printf("%lld\n", ans);
	}
}
int main()
{
	init();
	while(scanf("%d", &n) && n)
	{
		read();
		solve();
	}
	return 0;
}

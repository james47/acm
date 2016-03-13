//Accepted on CF GYM 100548
//Wrong Answer on uvalive 似乎不是程序问题
//now AC on uvalive 貌似之前没数据
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T, n, size, a[4], len;
int b[35];
long long t[1000000];
int s[1000000][2];
void decode(int a[], int b[]){
	for (int i = 0; i < 4; i++){
		int tmp = a[i];
		for (int j = 0; j < 8; j++){
			b[(3-i)*8+j] = tmp & 1;
			tmp >>= 1;
		}
	}
}
void tobin(long long x, int b[]){
	for (int i = 0; i < 32; i++){
		b[i] = x & 1;
		x >>= 1;
	}
}
void code(int a[], int b[]){
	for (int i = 0; i < 4; i++){
		int tmp = 0;
		for (int j = 0; j < 8; j++) tmp += b[(3-i)*8+j] * (1 << j);
		a[i] = tmp;
	}
}

void insert(int d[], int len){
	int id = 0; long long x = 0, f = 1ll << 31;
	for (int i = 31; i >= 32-len; i--){
		if (d[i]) x += f; f /= 2ll;
		if (s[id][d[i]] == -1){
			t[size] = x; s[size][0] = s[size][1] = -1;
			s[id][d[i]] = size;
			id = size ++;
		}
		else if (s[id][d[i]] == -2) return;	
		else id = s[id][d[i]];
	}
	s[id][0] = s[id][1] = -2;
}
void output(long long x, int dep){
	tobin(x, b); code(a, b);
	printf("%d.%d.%d.%d/%d\n", a[0], a[1], a[2], a[3], dep);
}
int cnt(int x, int dep){
	if (s[x][0] == -2) return 0;
	if (s[x][0] == -1 && s[x][1] == -1) return 1;
	int ret = 0;
	if (s[x][0] != -1) ret += cnt(s[x][0], dep+1);
	else ret ++;
	if (s[x][1] != -1) ret += cnt(s[x][1], dep+1);
	else ret ++;
	return ret;
}
void work(int x, int dep){
	if (s[x][0] == -2) return;
	if (s[x][0] == -1 && s[x][1] == -1){
		output(t[x], dep);
		return;
	}
	if (s[x][0] != -1) work(s[x][0], dep+1);
	else output(t[x], dep+1);
	if (s[x][1] != -1) work(s[x][1], dep+1);
	else output(t[x] + (1 << (31-dep)), dep+1);
}
int main()
{
	scanf("%d", &T);
	int cas = 0;
	while(T--){
		scanf("%d", &n);
		size = 1; t[0] = 0; s[0][0] = s[0][1] = -1;
		for (int i = 0; i < n; i++){
			scanf("%d.%d.%d.%d/%d", a+0, a+1, a+2, a+3, &len);
			decode(a, b);
			insert(b, len);
		}
		printf("Case #%d:\n", ++cas);
		printf("%d\n", cnt(0, 0));
		work(0, 0);
	}
	return 0;
}

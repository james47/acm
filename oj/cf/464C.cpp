#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;
const int maxn = 100000;
const int mod = (int)(1e9)+7;
char buf[maxn+10], tmp[maxn+10];
int n, x, size;
int b[maxn+10], q[maxn+10], st[maxn+10], ed[maxn+10];
LL l[maxn+10], to[maxn+10];
LL pow_mod(LL a, LL exp, LL mod){
	LL ret = 1;
	for (; exp; exp >>= 1, a = a*a % mod)
		if (exp & 1) ret = ret * a % mod;
	return ret;
}
int main()
{
	scanf("%s %d", buf, &n);
	size = 0;
	for (int i = 0; i < n; i++){
		scanf("%d-%s", &q[i], tmp);
		int len = strlen(tmp);
		if (len == 1){
			st[i] = ed[i] = 0;
			continue;
		}
		st[i] = size;
		for (int j = 1; j < len; j++) b[size++] = tmp[j] - '0';
		ed[i] = size;
	}
	for (int i = 0; i < 10; i++) l[i] = 1, to[i] = i;
	for (int i = n-1; i+1; i--){
		LL t = 0, len = 0;
		for (int j = st[i]; j < ed[i]; j++){
			t = (t * pow_mod(10, l[b[j]], mod) % mod + to[b[j]]) % mod;
			len = (len + l[b[j]]) % (mod-1);
		}
		to[q[i]] = t, l[q[i]] = len;
	}
	LL ans = 0; int len = strlen(buf);
	for (int i = 0; i < len; i++)
		ans = (ans * pow_mod(10, l[buf[i]-'0'], mod) % mod + to[buf[i]-'0']) % mod;
	cout << ans << endl;
	return 0;
}

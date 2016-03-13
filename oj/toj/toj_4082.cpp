#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int n, x;
vector<int> v[1010];
long long cal(int id){
	long long ret = 0;
	int size = v[id].size();
	for (int i = size-1, j = 1; i >= 0; i--, j ^= 1){
		if (j) ret = ret + v[id][i];
	}
	if (size & 1) ret += (n - size) / 2;
	else ret += (n - size + 1) / 2;
	return ret;
}
int pn = 0;
int mpf[1100], prime[1100];
void getprime(){
	memset(mpf, 0, sizeof(mpf));
	int ps = 1001;
	for (int i = 2; i < ps; i++){
		if (mpf[i] == 0) prime[pn++] = i;
		for (int j = 0; j < pn && i * prime[j] < ps && (prime[j] <= mpf[i] || mpf[i] == 0); j++)
			mpf[i * prime[j]] = prime[j];
	}
}
long long cnt[1100];
int f(int x){
	if (x == 1){
		cnt[1] ++;
		return 1;
	}
	for (int i = 0; i < pn; i++){
		if (x % prime[i] == 0){
			cnt[prime[i]] += x;
			return prime[i];
		}
	}
}
int main()
{
	int cas = 0;
	getprime();
	while(scanf("%d", &n) && n){
		for (int i = 1; i <= 1000; i++){
			v[i].clear();
			cnt[i] = 0;
		}
		int maxx = 1, tmp, sub = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &x);
			if (x == 0){
				sub++; continue;
			}
			tmp = f(x); 
			maxx = max(maxx, tmp);
			v[tmp].push_back(x);
		}
		n -= sub;
		long long ans = 0, buf;
		for (int i = maxx; i >= 1; i--) if (cnt[i] > ans){
			sort(v[i].begin(), v[i].end());
			buf = cal(i);
			if (buf > ans) ans = buf;
		}
		printf("Case #%d: %lld\n", ++cas, ans);
	}
	return 0;
}

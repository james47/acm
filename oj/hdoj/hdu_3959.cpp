#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
ll n, m, mm, x;
int T, cas;
ll gcd(ll a, ll b){
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%I64d %I64d", &n, &m);
		x = 1, mm = m;
		while(mm < n){
			mm *= m; x++;
		}
		ll a = x * mm, b = n, tmp;
		tmp = gcd(a, b);
		a /= tmp, b /= tmp;
		printf("Case %d: %I64d/%I64d\n", ++cas, a, b);
	}
	return 0;
}

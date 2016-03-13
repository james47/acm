#include<cstdio>
#include<cstring>
using namespace std;


long long n, inte, a, b, c, d;
long long gcd(long long a, long long b){
	if (b == 0) return a;
	else return gcd(b, a % b);
}
int main()
{
	while(scanf("%lld", &n) != EOF){
		inte = a = b = 0;
		for (long long i = 1; i <= n; i++){
			inte += n / i;
			d = n % i, c = i;
			if (b == 0) a = c, b = d;
			else{
				long long ta = a, tb = b;
				a = ta * c;
				b = tb * c + ta * d;
				inte += b / a;
				b %= a;
				if (b != 0){
					long long fac = gcd(a, b);
					a /= fac;
					b /= fac;
				}
			}
		}
		if (b == 0) printf("%lld\n", inte);
		else{
			long long tmp = inte;
			int cnt = 0;
			while(tmp) tmp /= 10, cnt ++;
			for (int i = 0; i <= cnt; i++) printf(" ");
			printf("%lld\n", b);
			printf("%lld ", inte);
			tmp = a;	
			int cnt1 = 0;
			while(tmp) tmp /= 10, cnt1 ++;
			for (int i = 0; i < cnt1; i++) printf("-");
			printf("\n");
			for (int i = 0; i <= cnt; i++) printf(" ");
			printf("%lld\n", a);
		}
	}
	return 0;
}

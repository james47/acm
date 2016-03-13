#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

const long long maxn = 1001000;
	long long _min(long long a, long long b){
		if (a < b) return a; else return b;
	}
	long long biggest(long long n){
		long long lim = _min(maxn, n);
		//printf("%lld %lld\n", maxn, n);
		long long ans = 0;
		for (long long i = 1; i <= lim; ++i){
			if (n % i == 0){
				long long t1 = i;
				long long t2 = n / i;
				long long rt1 = sqrt(t1);
				long long rt2 = sqrt(t2);
				if ((n % (i*i) == 0 && (i*i > ans)){
						ans = i * i;
				}
		//		printf("%lld %lld %lld %lld %lld\n", i, t1, t2, rt1, rt2);
				if (t1 > ans && rt1 * rt1 == t1){
					ans = t1;
				}
				if (t2 > ans && rt2 * rt2 == t2){
					ans = t2;
				}
			}
		}
		return ans;
	}

long long n; 
int main()
{
	scanf("%lld", &n);
	printf("%lld\n", biggest(n));
	return 0;
}


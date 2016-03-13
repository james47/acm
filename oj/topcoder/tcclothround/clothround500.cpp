#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const long long maxn = 1001000;
class SquareDivisor{
public:
	long long _max(long long a, long long b){
		if (a > b) return a; else return b;
	}
	long long biggest(long long n){
		long long lim = _max(maxn, n);
		long long ans = 0;
		for (long long i = 1; i <= lim; ++i){
			if (n % i){
				long long t1 = i;
				long long t2 = n / i;
				long long rt1 = sqrt(t1);
				long long rt2 = sqrt(t2);
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
};

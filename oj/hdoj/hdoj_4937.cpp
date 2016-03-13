#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int T, cas = 0, ans;
long long x;
void output()
{
	printf("Case #%d: %d\n", ++cas, ans);
}
bool ok(long long x, long long base)
{
	int tmp, cnt = 0;
	while(x){
		tmp = x % base;
		if (tmp < 3 || tmp > 6) return false;
		x /= base;
		cnt ++;
	}
	if (cnt > 3) return true;
	return false;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld", &x);
		ans = 0;
		if (3 <= x && x <= 6){
			ans = -1;
			output();
			continue;
		}
		for (int i = 3; i <= 6; i++)
			for (int j = 3; j <= 6; j++)
				if ((x-i) % j == 0){
					long long base = (x-i)/j;
					if (base > i && base > j) ans++;
				}
		for (int i = 3; i <= 6; i++)
			for (int j = 3; j <= 6; j++)
				for (int k = 3; k <= 6; k++){
					long long a = i, b = j, c = -x+k;
					long long delta = b * b - 4ll * a * c;
					if (delta <= 0) continue;
					long long srt = sqrt(double(delta));
					if (srt * srt == delta){
						long long tmp = -b + srt;
						if (tmp % (a*2ll) == 0){
							long long base = tmp / (2ll*a);
							if (base > i && base > j && base > k) ans++;
						}
					}
				}
		for (int base = 4; base <= 7000; base++){
			if (ok(x, base)) ans++;
		}
		output();
	}
	return 0;
}

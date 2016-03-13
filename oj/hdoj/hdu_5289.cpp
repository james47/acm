#include<cstdio>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;

int T, n, k;
set<pair<int, int> > s;
int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &n, &k);
		s.clear();
		set<pair<int, int> >::iterator it;
		set<pair<int, int> >::reverse_iterator rit;
		long long ans = 0; int x, h = 1;
		for (int i = 1; i <= n; i++){
			scanf("%d", &x);
			while(!s.empty()){
				it = s.begin();
				if (abs(x - it->first) >= k){
					h = max(h, it->second + 1);
					s.erase(*it);
				}
				else break;
			}
			while(!s.empty()){
				rit = s.rbegin();
				if (abs(rit->first - x) >= k){
					h = max(h, rit->second + 1);
					s.erase(*rit);
				}
				else break;
			}
			ans += i - h + 1;
			s.insert(make_pair(x, i));
		}
		printf("%I64d\n", ans);
	}
	return 0;
}

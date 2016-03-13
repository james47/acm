#include<cstdio>
#include<cstring>
using namespace std;

int n;
int s[100000];
int main()
{
	s[0] = 0; s[1] = 1; s[2] = 3;
	for (int i = 3; ; i++){
		s[i] = s[i-1] + s[i-1] + 1;
		if (s[i] >= 100000) break;
	}
	while(scanf("%d", &n) != EOF){
		int ans;
		for (int i = 1; ; i++) if (s[i] >= n){ans = i; break;}
		printf("%d\n", ans);
	}
	return 0;
}

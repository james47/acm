#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = (int)1e6+1000;
int up[maxn], low[maxn];
char str[maxn];
int main()
{
	while(scanf("%s", str) != EOF)
	{
		int n = strlen(str);
		low[n] = up[n] = 0;
		bool none = false;
		for (int i = n-1; i >= 0; i--){
			up[i] = up[i+1]; low[i] = low[i+1];
			if (str[i] == '('){
				up[i]--; low[i]--;
			}
			else if (str[i] == '?'){
				up[i]++; low[i]--;
			}
			else if (str[i] == ')'){
				up[i]++; low[i]++;
			}
			if (low[i] < 0) low[i] += 2;
			if (up[i] < 0) { none = true; break; }
		}
		if (low[0] != 0) none = true;
		if (none){
			puts("None");
			continue;
		}
		bool unique = true;
		int delta = 0;
		for (int i = 0; i < n-1; i++){
			if (str[i] == '?'){
				int x = 0;
				if (low[i+1] <= delta + 1 && delta + 1 <= up[i+1])
					x |= 1;
				if (delta && low[i+1] <= delta - 1 && delta - 1 <= up[i+1])
					x |= 2;
				if (x == 1) str[i] = '(';
				else if (x == 2) str[i] = ')';
				else { unique = false; break; }
			}
			if (str[i] == '(') delta++;
			else delta--;
		}
		if (unique) puts("Unique");
		else puts("Many");
	}
	return 0;
}

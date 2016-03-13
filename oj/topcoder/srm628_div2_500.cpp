#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;

int d[200][200];
bool match(int a, int b, string s)
{
	if (s[a] == 'X')
		if (s[b] == '}' || s[b] == ')' || s[b] == ']' || s[b] == 'X') return true;
	if (s[b] == 'X')
		if (s[a] == '(' || s[a] == '{' || s[a] == '[' || s[a] == 'X') return true;
	if (s[a] == '(' && s[b] == ')') return true;
	if (s[a] == '{' && s[b] == '}') return true;
	if (s[a] == '[' && s[b] == ']') return true;
	return false;
}

class BracketExpressions{
public:
	string ifPossible(string s)
	{	
		int len = s.length();
		for (int i = 0; i < len; i++)
			d[i][i] = 1;
		for (int i = 0; i < len-1; i++) if (match(i, i+1, s))
			d[i][i+1] = 0;
		for (int k = 1; k < len; k++)
			for (int i = 0; i < len; i++){
				int j = i + k;
				if (j >= len) break;
				d[i][j] = 214748360;
				if (match(i, j, s))
					d[i][j] = d[i+1][j-1];
				for (int m = i; m < j; m++)
					d[i][j] = min(d[i][j], d[i][m] + d[m+1][j]);
			}
		if (d[0][len-1] == 0) return "possible";
		else return "impossible";
	}
};

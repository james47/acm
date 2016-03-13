#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<ctime>
#include<string>
using namespace std;

char str[1000];
bool v[500];
int main()
{
	memset(v, 0, sizeof(v));
	while(gets(str))
	{
		int len = strlen(str);
		for (int i = 0; i < len; i++){
			char ch = str[i];
			if (ch == ' ') continue;
			if (ch == '`'){
				if (str[i+1] == '`'){
					v[394] = true;
					i += 1;
				}
				else v[395] = true;
				continue;
			}
			if (ch == '\''){
				if (str[i+1] == '\''){
					v[392] = true;
					i += 1;
				}
				else v[393] = true;
				continue;
			}
			if (ch != 'f'){
				v[ch] = true;
				continue;
			}	
			char tmp = str[i+1];
			if (tmp == 'f' || tmp == 'i' || tmp == 'l'){
				if (tmp == 'f'){
					char tmp2 = str[i+2];
					if (tmp2 == 'i' || tmp2 == 'l'){
						i += 2;
						if (tmp2 == 'i') v[398] = true;
						if (tmp2 == 'l') v[396] = true;
					}
					else{
						i += 1;
						v[400] = true;
					}
				}
				else{
					i += 1;
					if (tmp == 'i') v[399] = true;
					if (tmp == 'l') v[397] = true;
				}
			}
			else v[ch] = true;
		}
	}
	int ans = 0;
	for (int i = 0; i <= 400; i++)
		if (v[i]) ans++;
	printf("%d\n", ans);
	return 0;
}

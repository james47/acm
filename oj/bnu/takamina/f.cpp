#include<cstdio>
#include<cstring>
using namespace std;

bool v[300];
int main()
{
	memset(v, 0, sizeof(v));
	char ch;
	while(1){
		ch = getchar();
		if (ch == '}') break;
		if (ch >= 'a' && ch <= 'z') v[ch] = true;
	}
	int cnt = 0;
	for (int i = 'a'; i <= 'z'; i++) if (v[i]) cnt ++;
	printf("%d\n", cnt);
	return 0;
}

#include<cstdio>
#include<set>
#include<cstring>
#include<string>
using namespace std;

char buf[1000000], word[10000];
set<string> s;
bool read(char buf[], char word[], int &pos, int len){
	char ch = ' ';
	while(pos < len && ch == ' ') ch = buf[pos++];
	if (ch == ' ') return 0;
	int l = 0;
	while(pos < len && ch != ' '){
		word[l++] = ch;
		ch = buf[pos++];
	}
	if (ch != ' ') word[l++] = ch;
	word[l] = 0;
	return 1;
}
int main()
{
	while(gets(buf) && buf[0] != '#'){
		s.clear();
		int pos = 0, len = strlen(buf);
		while (read(buf, word, pos, len)) s.insert(word);
		printf("%d\n", (int)s.size());
	}
	return 0;
}

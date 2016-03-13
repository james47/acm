#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;

map<string, string> mp;
map<string, string>::iterator ite;
char buf[20], fo[20];
int main()
{
	mp.clear();
	char ch;
	while(scanf("%s", buf) != EOF){
		ch = getchar();
		if (ch == ' '){
			scanf("%s", fo);
			mp[fo] = buf;//?
		}
		else{
			ite = mp.find(buf);
			if (ite != mp.end()) printf("%s\n", ite->second.c_str());
			else printf("eh\n");
			break;
		}
	}
	while(scanf("%s", buf) != EOF){
		ite = mp.find(buf);
		if (ite != mp.end()) printf("%s\n", ite->second.c_str());
		else printf("eh\n");
	}
	return 0;
}

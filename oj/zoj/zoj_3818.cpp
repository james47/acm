#include<cstdio>
#include<cstring>
using namespace std;

int n, len;
char str[300];
bool ok(int la, int lb, int len)
{
	int sta = 0, eda = la-1, stb = la, edb = la+lb-1;
	if (la == lb){
		bool equal = true;
		for (int i = sta, j = stb; i <= eda; i++, j++)
			if (str[i] != str[j]){
				equal = false;
				break;
			}
		if (equal) return false;
	}
	//ababa
	if (la+lb+la+lb+la == len){
		bool find = true;
		int sta2, eda2, stb2, edb2, sta3;
		sta2 = edb +1; eda2 = sta2+la-1;
		stb2 = eda2+1; edb2 = stb2+lb-1;
		sta3 = edb2+1;
		for (int i = sta, j = sta2, k = sta3; i <= eda; i++, j++, k++){
			if (str[i] != str[j] || str[i] != str[k]){
				find = false;
				break;
			}
		}
		if (find){
			for (int i = stb, j = stb2; i <= edb; i++, j++){
				if (str[i] != str[j]){
					find = false;
					break;
				}
			}
		}
		if (find) return true;
	}
	//ababcab
	if (3*(la+lb) < len){
		bool find = true;
		int lc = len - 3*(la+lb);
		int sta2, eda2, stb2, edb2, stc, edc, sta3, eda3, stb3, edb3;
		sta2 = edb +1; eda2 = sta2+la-1;
		stb2 = eda2+1; edb2 = stb2+lb-1;
		stc  = edb2+1; edc  = stc+lc-1;
		sta3 = edc +1; eda3 = sta3+la-1;
		stb3 = eda3+1; edb3 = stb3+lb-1;
		if (la == lc){
			bool equal = true;
			for (int i = sta, j = stc; i <= eda; i++, j++){
				if (str[i] != str[j]){
					equal = false;
					break;
				}
			}
			if (equal) return false;
		}
		if (lb == lc){
			bool equal = true;
			for (int i = stb, j = stc; i <= edb; i++, j++){
				if (str[i] != str[j]){
					equal = false;
					break;
				}
			}
			if (equal) return false;
		}
		for (int i = sta, j = sta2, k = sta3; i <= eda; i++, j++, k++){
			if (str[i] != str[j] || str[i] != str[k]){
				find = false;
				break;
			}
		}
		if (find){
			for (int i = stb, j = stb2, k = stb3; i <= edb; i++, j++, k++){
				if (str[i] != str[j] || str[i] != str[k]){
					find = false;
					break;
				}
			}
		}
		if (find) return true;
	}
	return false;
}
int main()
{
	scanf("%d", &n);
	while(n--){
		scanf("%s", str);
		int size = strlen(str);
		len = 0;
		for (int i = 0; i < size; i++){
			if (('a' <= str[i] && str[i] <= 'z')||('A' <= str[i] && str[i] <= 'Z')) 
				str[len++] = str[i];
		}
		bool findans = false;
		for (int i = 1; (i < len)&&(!findans); i++)
			for (int j = 1; j < len; j++){
				if (ok(i, j, len)){
					findans = true;
					break;
				}
			}
		if (findans) puts("Yes");
		else puts("No");
	}
	return 0;
}

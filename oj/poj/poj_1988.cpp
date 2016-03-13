#include<cstdio>
#include<cstring>
using namespace std;

int p;
int f[30100], c[30100], s[30100];
int getf(int x){
	if (x == f[x]) return x;
	int fa = f[x];
	f[x] = getf(f[x]);
	c[x] = c[fa] + c[x];
	return f[x];

}
void merge(int x, int y){
	int fx = getf(x), fy = getf(y);
//	printf("%d %d %d %d\n", x, y, fx, fy);
	if (fx != fy){
//		printf("%d %d %d %d\n", c[fx], s[fx], c[fy], s[fy]);
		f[fx] = fy;
		c[fx] = s[fy] + 1;
		s[fy] += s[fx] + 1;
//		printf("%d %d %d %d\n", c[fx], s[fx], c[fy], s[fy]);
	}
}
char buf[10];
int main()
{
	while(scanf("%d", &p) != EOF){
		for (int i = 0; i <= 30000; i++){
			f[i] = i; c[i] = s[i] = 0;
		}
		int x, y;
		while(p--){
			scanf("%s", buf);
			if (buf[0] == 'M'){
				scanf("%d %d", &x, &y);
				merge(x, y);
			}
			else{
				scanf("%d", &x);
				getf(x);
				printf("%d\n", c[x]);
			}
		}
	}
	return 0;
}

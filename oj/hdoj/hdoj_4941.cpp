#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

typedef pair<int, int> P;
int T, n, m, k, x, y, c, q;
map<P, int> p;
map<int, int> row, col;

int main()
{
	scanf("%d", &T);
	int cas = 0;
	while(T--)
	{
		p.clear();
		row.clear(); col.clear();
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < k; i++){
			scanf("%d %d %d", &x, &y, &c);
			row[x] = x; col[y] = y;
			P tmp = make_pair(x, y);
			p[tmp] = c;
		}
		printf("Case #%d:\n", ++cas);
		scanf("%d", &q);
		for (int i = 0; i < q; i++){
			scanf("%d %d %d", &c, &x, &y);
			if (c == 1) swap(row[x], row[y]);
			else if (c == 2) swap(col[x], col[y]);
			else{
				P tmp = make_pair(row[x], col[y]);
				printf("%d\n", p[tmp]);
			}	
		}
	}
	return 0;
}

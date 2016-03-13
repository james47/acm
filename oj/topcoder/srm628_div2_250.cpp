#include<cstdio>
#include<cmath>
#include<algorihtm>
using namespace std;
class BishopMove{
public:
	int howManyMoves(int r1, int c1, int r2, int c2)
	{
		int ans = -1;
		if (r1 == r2 && c1 == c2) ans = 0;
		else if (abs(r1 - r2) == abs(c1 - c2)) ans = 1;
		else if ((r1+c1) % 2 == (r2+c2) % 2) ans = 2;
		return ans;
	}
}
int main()
{
	int x1, x2, y1, y2;
	while(scanf("%d %d %d %d", &x1, &y1, &x2, &y2)!= EOF){
		printf("%d\n" howManyMoves(x1, y1, x2, y2));
	}
	return 0;
}

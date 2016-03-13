#include<cstdio>
#include<cstring>
using namespace std;

const int size = 20345677;
const int key = 991;
int hash[size], sum[size];
int a[4010][4];
void insert(int val)
{
	int tmp = (val + key) % size;
	if (tmp < 0) tmp += size;
	while(hash[tmp] != -1 && hash[tmp] != val)
		tmp = (tmp + key) % size;
	hash[tmp] = val;
	sum[tmp] ++;
}
int find(int val)
{
	int tmp = (val + key) % size;
	if (tmp < 0) tmp += size;
	while(hash[tmp] != -1 && hash[tmp] != val)
		tmp = (tmp + key) % size;
	return sum[tmp];
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	for (int j = 0; j < 4; j++)
	{
		scanf("%d", &a[i][j]);
	}
	memset(sum, 0, sizeof(sum));
	memset(hash, -1, sizeof(hash));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			insert(a[i][0] + a[j][1]);
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans += find(-(a[i][2] + a[j][3]));
	printf("%d\n", ans);
	return 0;
}

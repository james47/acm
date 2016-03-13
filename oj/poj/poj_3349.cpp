#include<cstring>
#include<cstdio>
using namespace std;

const int N =100000;
const int mo = 1000007;
int a[6], h[mo][6];
bool compare(int a[6], int b[6])
{
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			if (a[i] == b[j])
			{
				bool flag = true;
				for (int k = 1; k <= 5; k++)
				{	
					if (a[(i+k)%6] != b[(j+k)%6])
					{
						flag = false;
						break;
					}
				}
				if (flag) return true;
				flag = true;
				for (int k = 1; k <= 5; k++)
				{
					if (a[(i+k)%6] != b[(j-k+6)%6])
					{
						flag = false;
						break;
					}
				}
				if (flag) return true;
			}

	return false;
}
int Hash(int a[6])
{
	long long tot = 0;
	for (int i = 0; i < 6; i++)
	{
		tot += (long long)(a[i]) * (long long)(a[i]);
		if (tot >= mo) tot %= mo;
	}
	for (int i = 1; h[tot][0] != -1 && !compare(h[tot], a); i++)
	{
		tot += (long long)(i) * (long long)(i);
		if (tot >= mo) tot %= mo;
	}
	return tot;
}
int main()
{
        int n;
        scanf("%d", &n);
        memset(h, -1, sizeof(h));
	bool flag = false;
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < 6; j++)
                        scanf("%d", &a[j]);
                if (flag) continue;
		int key = Hash(a);
		if (h[key][0] != -1)
			flag = true;
		else
		{
			for (int j = 0; j < 6; j++)
				h[key][j] = a[j];
		}
        }
        if (flag)
                puts("Twin snowflakes found.");
        else
                puts("No two snowflakes are alike.");
	return 0;
}

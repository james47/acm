#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const double eps = 1e-6;
struct node{
	int s, t, p, w;
} p[int(1e5)+100];
int cas = 0, T, n, v1, v2;
int ans[int(1e5)+100];
double a[int(1e5)+100], b[int(1e5)+100];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d", &n, &v1, &v2);
		int max1 = 0, max2 = 0, cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; i++){
			scanf("%d %d %d %d", &p[i].s, &p[i].t, &p[i].p, &p[i].w);
			if (p[i].s == 1){
				max1 = max(max1, p[i].p);
			}
			if (p[i].s == 2){
				max2 = max(max2, p[i].p);
			}
		}
		printf("Case #%d:\n", ++cas);
		for (int i = 0; i < n; i++){
			if (p[i].s == 1){
				a[cnt1++] = ((double)p[i].t + (double)(max1-p[i].p) / (double)v2) * (double)v1;
			}
			if (p[i].s == 2){
				b[cnt2++] = ((double)p[i].t + (double)(max2-p[i].p) / (double)v1) * (double)v2;
			}
		}
		if (cnt1 == 0 || cnt2 == 0){
			for (int i = 0; i < n; i++) printf("0\n");
			continue;
		}
		sort(a, a+cnt1);
		sort(b, b+cnt2);
		//printf("%d %d\n", cnt1, cnt2);
		for (int i = 0; i < n; i++){
			if (p[i].s == 1){
				double tmp = double(max2)/v1;
				tmp = (tmp + p[i].t) * v2;
				int ans1, ans2;
				double key1 = tmp - p[i].p, key2 = tmp - p[i].p - p[i].w;
				if (key1 > b[cnt2-1]) ans1 = cnt2-1;
				else if (key1 < b[0]) ans1 = -1;
				else{
					int l = 0, r = cnt2-1;
					while(l <= r)
					{
						int mid = l + r >> 1;
						if (b[mid] - key1 < eps){
						//if (b[mid] <= key1){
							ans1 = mid;
							l = mid+1;
						}
						else r = mid-1;
					}
				}
				if (key2 > b[cnt2-1]) ans2 = cnt2;
				else if (key2 < b[0]) ans2 = 0;
				else{
					int l = 0, r = cnt2-1;
					while(l <= r)
					{
						int mid = l + r >> 1;
						if (b[mid] - key2 > -eps){
						//if (b[mid] >= key2){
							ans2 = mid;
							r = mid-1;
						}
						else l = mid+1;
					}
				}
				ans[i] = ans1 - ans2 + 1;
			}
			if (p[i].s == 2){
				double tmp = double(max1)/v2;
				tmp = (tmp + p[i].t) * v1;
				int ans1, ans2;
				double key1 = tmp - p[i].p, key2 = tmp - p[i].p - p[i].w;

				if (key1 > a[cnt1-1]) ans1 = cnt1-1;
				else if (key1 < a[0]) ans1 = -1; 
				else{
					int l = 0, r = cnt1-1;
					while(l <= r)
					{
						int mid = l + r >> 1;
						if (a[mid] - key1 < eps){
						//if (a[mid] <= key1){
							ans1 = mid;
							l = mid+1;
						}
						else r = mid-1;
					}
				}

				if (key2 > a[cnt1-1]) ans2 = cnt1;
				else if (key2 < a[0]) ans2 = 0;
				else{
					int l = 0, r = cnt1-1;
					while(l <= r)
					{
						int mid = l + r >> 1;
						if (a[mid] - key2 > -eps){
						//if (a[mid] >= key2){
							ans2 = mid;
							r = mid-1;
						}
						else l = mid+1;
					}
				}
				ans[i] = ans1 - ans2 + 1;
			//	printf("%d %d\n", ans1, ans2);
			//	printf("%.4f %.4f %.4f %d\n", key2, key1, a[0], cnt1);
			}
		}
		for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
	}
	return 0;
}

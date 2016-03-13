/*
这题没有做好，很遗憾。错在两个地方，一个是一个地方=打成==，一个是硬伤，c数组没有排序就做合并，比如[1,3],[4,7],[2,5]，如果没排序，[1,3]会和[2,5]合并，但是[4,7]就遗漏了。后来加了一个flag循环弥补这个漏洞。
其实这题暴力就可以过。总共大概15w天，直接建char数组用memset填充1和2两类，扫一遍。
或者是标号，每个端点日期打上标号，两种线段分别统计覆盖次数，如果查询区间线段覆盖数不为0而已有区间线段覆盖数为0，那么这一个点就标记为需要查询。最后还是扫一遍，连续需要查询的点一次输出。
数据大，可以再加离散化。
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<ctime>
#include<string>
using namespace std;
const int datac[13] = { -1 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
bool isleap(int x)
{
	if (x % 400 == 0 || (x % 100 != 0 && x % 4 == 0)) return true;
	return false;
}
struct data
{
	int y , d , m ;
	data(int _y,int _m,int _d):y(_y),m(_m),d(_d){}
	data(){}
	data next()
	{
		data p = *this;
		p.d ++;
		if (p.d == 29 && p.m == 2)
		{
			if (!isleap(p.y))
			//if ( p.y % 4 != 0 || ( p.y % 4 == 0 && p.y % 100 == 0 && p.y % 400 != 0) )
			{
				p.d = 1;
				p.m ++;
			}

		}
		else if ( p.m == 2 && p.d == 30){
			p.d = 1;
			p.m ++;
		}
		else if (datac[p.m] < p.d){
			p.d = 1;
			p.m ++;
			if (p.m == 13){
				p.y ++;
				p.m = 1;
			}
		}
		return p;
	}
	data pre()
	{
		data p = *this;
		p.d --;
		if (p.d == 0){
			p.m --;
			if (p.m == 0){
				p.m = 12;
				p.d = 31;
				p.y --;
			}
			else if (p.m == 2){
				if (isleap(p.y)) p.d = 29;
				else p.d = 28;
			}
			else{
				p.d = datac[p.m];
			}
		}
		return p;
	}
	bool operator < ( const data &p)
	{
		if ( this-> y < p.y ) return true;
		if ( this-> y == p.y && this->m < p.m ) return true;
		if ( this-> y == p.y && this->m == p.m && this->d < p.d) return true;
		return false;
	}
	bool operator == ( const data &p)
	{
		if ( this-> y == p.y && this->m == p.m && this->d == p.d) return true;
		return false;
	}
	bool operator <= (const data &p){
		if ((*this == p) || ( *this < p )) return true ; 
		return false;
	}
};
struct range{
	data b, e;
} raw[1000][2], a[10000][2], b[50000], c[50000];
bool vis[1000][2], vvis[50000];

int n[2];
int newsize;

data trans(int x)
{
	int day = x % 100;
	x /= 100;
	int mon = x % 100;
	x /= 100;
	data ret;
	ret.y = x;
	ret.d = day;
	ret.m = mon;
	return ret;
}
bool meet(range a, range b)
{
	if (b.b < a.b) swap(a, b);
	if (b.b <= a.e.next()) return true;
	return false;
}
bool realmeet(range a, range b)
{
	if (b.b < a.b) swap(a, b);
	if (b.b <= a.e) return true;
	return false;
}
range merge(range a, range b)
{
	range tmp;
	if (a.b < b.b) tmp.b = a.b;
	else tmp.b = b.b;
	if (a.e < b.e) tmp.e = b.e;
	else tmp.e = a.e;
	return tmp;
}
void work(int x, int &cnt){
	int len = n[x]; 
	for (int i = 0; i < len; i++) if(!vis[i][x]){
		vis[i][x] = true;
		range tmp = raw[i][x]; 
		for (int j = i+1; j < len; j++)
			if (!vis[j][x]){
				if (meet(tmp, raw[j][x])){
					vis[j][x] = true;
					tmp = merge(tmp, raw[j][x]);
				}
			}
		a[cnt++][x] = tmp;
	}
//	printf("%d\n",cnt);
//	for (int i = 0; i < cnt; i++)
//		printf("%d %d %d \n", a[i][x].b.d, a[i][x].b.m, a[i][x].b.y);
}
void cook(int &cnt1, int &cnt2)
{
	memset(vis, 0, sizeof(vis));
	cnt1 = cnt2 = 0;
	work(0, cnt1);
	work(1, cnt2);
}
void dfs(range x, int dep, int lim)
{
	if (x.e < x.b) return;
	if (dep == lim){
		b[newsize++] = x;
		return;
	}
	range tmp = a[dep][0];
	if (realmeet(tmp, x)){
		if (tmp.b <= x.b && x.e <= tmp.e) return; //be included;
		if (x.b < tmp.b && tmp.e < x.e){  //include tmp
			range x1, x2;
			x1.b = x.b; x1.e = tmp.b.pre();
			x2.b = tmp.e.next(); x2.e = x.e;
			dfs(x1, dep+1, lim);
			dfs(x2, dep+1, lim);
			//dfs(x1, 0, lim);
			//dfs(x2, 0, lim);
		}
		else{
			range nx;
			if (x.b < tmp.b) nx.b = x.b;
			else nx.b = tmp.e.next();
			if (x.e <= tmp.e) nx.e = tmp.b.pre();
			else nx.e = x.e;
			//dfs(nx, 0, lim);
			dfs(nx, dep+1, lim);
		}
	}
	else dfs(x, dep+1, lim);
}
bool cmp(range a, range b)
{
	return a.b < b.b;
}
int main()
{
	int cas = 0;
	while(scanf("%d %d", n+0, n+1) && n[0] + n[1])
	{
		if (cas != 0) printf("\n");
		int tmp, tmp1;
		for (int i = 0; i < n[0]; i++){
			scanf("%d %d", &tmp, &tmp1);
			data tmpp = trans(tmp); raw[i][0].b = tmpp;
			tmpp = trans(tmp1); raw[i][0].e = tmpp;
		}
		for (int i = 0; i < n[1]; i++){
			scanf("%d %d", &tmp, &tmp1);
			data tmpp = trans(tmp); raw[i][1].b = tmpp;
			tmpp = trans(tmp1); raw[i][1].e = tmpp;
		}
		int size1, size2;
		cook(size1, size2);

		//printf("%d %d\n", size1, size2);

		newsize = 0;
		for (int i = 0; i < size2; i++){
			dfs(a[i][1], 0, size1); 
		}


		memset(vvis, 0, sizeof(vvis));
		int newnewsize = 0;
	//	for (int i = 0; i < newsize; i++){
	//		printf("%d %d %d %d %d %d %d\n", i, b[i].b.y, b[i].b.m, b[i].b.d, b[i].e.y, b[i].e.m, b[i].e.d);
	//	}
		for (int i = 0; i < newsize; i++) if (!vvis[i]){
			vvis[i] = true;
			range tmp = b[i];
			bool flag = true;
			while (flag){
				flag = false;
				for (int j = i+1; j < newsize; j++) if(!vvis[j]){
					if (meet(tmp, b[j])){
						//printf("%d is merge by %d \n", j, i);
						flag = true;
						vvis[j] = true;
						tmp = merge(tmp, b[j]);
					}
				}
			}
			c[newnewsize++] = tmp;
		}

//		printf("%d\n", newsize);
//		for (int i = 0; i < newsize; i++){
//			printf("%d %d %d\n", b[i].b.d, b[i].b.m, b[i].b.y);
//		}
//		printf("%d\n", newnewsize);

		sort(c, c+newnewsize, cmp);
		printf("Case %d:\n", ++cas);
		if (newnewsize == 0){
			puts("No additional quotes are required.");
		}
		for (int i = 0; i < newnewsize; i++){
			if (c[i].b == c[i].e){
				printf("%d/%d/%d\n", c[i].b.m, c[i].b.d, c[i].b.y);
			}
			else{
				printf("%d/%d/%d to %d/%d/%d\n", c[i].b.m, c[i].b.d, c[i].b.y, c[i].e.m, c[i].e.d, c[i].e.y);
			}
		}

	}
	return 0;
}


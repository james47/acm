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

int n, k;

struct Nodea{
	int data[1008][10];
}   a;
struct Nodeb{
	int data[10][1008];
}   b;
struct Nodem{
	int data[10][10];
}   m, tmp;
struct Nodeans{
	int data[1008][1008];
}    ans;

Nodem mulba(Nodeb b,Nodea a)
{
	Nodem    mx;
	for (int i=0;i<k;i++)
		for (int j=0;j<k;j++)
			mx.data[i][j] = 0;
	for (int i=0;i<k;i++)
		for (int j=0;j<k;j++)
			for (int w=0;w<n;w++)
				mx.data[i][j] = (b.data[i][w]*a.data[w][j]+mx.data[i][j]) %6;
	return mx;
}

Nodem mulmm(Nodem a,Nodem b)
{
	Nodem    mx;
	for (int i=0;i<k;i++)
		for (int j=0;j<k;j++)
			mx.data[i][j] = 0;
	for (int i=0;i<k;i++)
		for (int j=0;j<k;j++)
			for (int w=0;w<k;w++)
				mx.data[i][j] = (a.data[i][w]*b.data[w][j]+mx.data[i][j]) % 6;
	return mx;
}

Nodem powc(int b)
{
	if (b==1)       return   m;
	if (b==2)       return mulmm(m,m);
	Nodem mx = powc(b/2);
	mx = mulmm(mx,mx);
	if (b%2==1)     mx = mulmm(mx,m);
	return mx;
}


Nodea mulam(Nodea a,Nodem m)
{
	Nodea    mx;
	for (int i=0;i<n;i++)
		for (int j=0;j<k;j++)
			mx.data[i][j] = 0;
	for (int i=0;i<n;i++)
		for (int j=0;j<k;j++)
			for (int w=0;w<k;w++)
				mx.data[i][j] = (a.data[i][w]*m.data[w][j]+mx.data[i][j]) % 6;
	return mx;
}

void mulab(Nodea a,Nodeb b)
{
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			ans.data[i][j] = 0;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			for (int w=0;w<k;w++)
				ans.data[i][j] = (a.data[i][w]*b.data[w][j]+ans.data[i][j]) % 6;
}

int read()
{
	int ret = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret;
}
int main()
{
	while (scanf("%d %d",&n,&k),n+k){
		for (int i=0;i<n;i++)
			for (int j=0;j<k;j++)   a.data[i][j] = read();//scanf("%d",&a.data[i][j]);
		for (int i=0;i<k;i++)
			for (int j=0;j<n;j++)   b.data[i][j] = read();//scanf("%d",&b.data[i][j]);
		m = mulba(b,a);
		int exp = n * n - 1;
		tmp = m;
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 6; j++)
				m.data[i][j] = 0;
		for (int i = 0; i < 6; i++)
			m.data[i][i] = 1;
		while(exp){
			if (exp & 1) m = mulmm(m, tmp);
			tmp = mulmm(tmp, tmp);
			exp >>= 1;
		}

		a = mulam(a,m);
		mulab(a,b);
		int sum = 0;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				sum += ans.data[i][j];
		printf("%d\n",sum);
	}
	return 0;
}

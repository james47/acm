/*************************************************************************
    > File Name: d.cpp
    > Author: james47
    > Mail: 
    > Created Time: Wed Jul 15 15:51:58 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
struct seg{
	ll l, r;
	seg(){}
	seg(ll L, ll R): l(L), r(R){}
	bool operator < (const seg& cmp) const{
		if (l == cmp.l) return r < cmp.r;
		return l < cmp.l;
	}
} s0[100100], s1[100100];
int h, q, a, d, n0, n1;
ll b, c;
ll L, R;

ll getl(int a, int h, ll b){
	ll ret = b;
	for (int i = a; i < h; i++){
		ret *= 2ll;
	}
	return ret;
}
ll getr(int a, int h, ll c){
	ll ret = c;
	for (int i = a; i < h; i++){
		ret = ret * 2 + 1;
	}
	return ret;
}

int main()
{
	scanf("%d %d", &h, &q);
	n0 = n1 = 0;
	for (int i = 0; i < q; i++){
		scanf("%d %I64d %I64d %d", &a, &b, &c, &d);
		L = getl(a, h, b); R = getr(a, h, c);
		if (d){
			s1[n1++] = seg(L, R);
		}
		else{
			s0[n0++] = seg(L, R);
		}
	}
	L = getl(1, h, 1); R = getr(1, h, 1);
	for (int i = 0; i < n1; i++)
		L = max(L, s1[i].l), R = min(R, s1[i].r);
	if (L > R){
		puts("Game cheated!");
		return 0;
	}

//
//	for (int i = 0; i < n0; i++){
//		cout << s0[i].l << ' ' << s0[i].r << endl;
//	}
//
//	cout << L << ' ' << R << endl;

	ll tot = 0, ans;
	sort(s0, s0+n0);
	for (int i = 0; i < n0; i++){
		if (s0[i].r < L) continue;
		if (s0[i].l > R) break;
		if (s0[i].l <= L){
			L = s0[i].r + 1;
		}
		else{
			tot += s0[i].l - L;
			ans = s0[i].l - 1;
			L = s0[i].r + 1;
		}
		if (L > R) break;
		/*
		if (s0[i].l >= L){
			tot += min(R+1, s0[i].l) - L;
			if (s0[i].l > L) ans = s0[i].l-1;
		}
		L = max(L, s0[i].r + 1);
		if (L > R) break;
		*/
	}
//	cout << L << ' ' << R << endl;
	if (L <= R){
		tot += R - L + 1;
		ans = R;
	}
	if (tot == 0){
		puts("Game cheated!");
	} 
	else if (tot == 1){
		cout << ans << endl;
	}
	else{
		puts("Data not sufficient!");
	}
	return 0;
}

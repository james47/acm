/*************************************************************************
    > File Name: hdoj_5469.cpp
    > Author: james47
    > Mail: 
    > Created Time: Wed Oct 14 14:56:24 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

template<class T>
inline bool read(T &n){
    T x = 0, tmp = 1; char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}

#define debug 0
typedef unsigned long long ll;
typedef pair<int, int> pii;
const int seed = 10003;
const int maxn = 1e4+10;

struct edge{
	int v, n;
} e[maxn<<2];
int esize;

bool vis[maxn];
int en[maxn], sz[maxn], dis[maxn], fa[maxn], q[maxn], match[maxn];
ll B[maxn], lha[maxn], rha[maxn], pre[maxn], suf[maxn];
char s[maxn], c[maxn];
int n, L;

void addedge(int u, int v){
	e[esize].v = v;
	e[esize].n = en[u];
	en[u] = esize ++;
}

void init(){
	esize = 0;
	memset(en, -1, sizeof(int)*(n+1));
	memset(vis, 0, sizeof(bool)*(n+1));
}
void get_size(int x, int f){
	sz[x] = 1;
	for (int t = en[x]; t != -1; t = e[t].n){
		int v = e[t].v;
		if (v == f || vis[v]) continue;
		get_size(v, x);
		sz[x] += sz[v];
	}
}

pii get_root(int x, int f, int tot){
	pii ret = make_pair(min(sz[x]-1, tot-sz[x]), x);
	for (int t = en[x]; t != -1; t = e[t].n){
		int v = e[t].v;
		if (v == f || vis[v]) continue;
		pii tmp = get_root(v, x, tot);
		if (tmp < ret) ret = tmp;
	}
	return ret;
}

int go(int x){
	int head = 0, tail = 0, ret = 0;
	for (q[tail++] = x; head < tail; head++){
		int u = q[head];
		if (dis[u] <= L && rha[u] == suf[dis[u]]){
		//	if (debug) printf("match suf %d, from %d to %d\n", dis[u], x, u);
			match[dis[u]] ++;
		}
		//else if (debug) printf("%d\n", u);
		for (int t = en[u]; t != -1; t = e[t].n){
			int v = e[t].v;
			if (v == fa[u] || vis[v]) continue;
			fa[v] = u, dis[v] = dis[u] + 1;
			lha[v] = lha[u] + B[dis[v]] * c[v];
			rha[v] = rha[u] + B[dis[v]-1] * c[v];
			q[tail++] = v;
		}
	}
	int pt, dist;
	for (int i = 0; i < tail; i++){
		pt = q[i]; dist = dis[pt];
		if (dist < L && lha[pt] == pre[dist+1]){
		//	if (debug) printf("match pre %d, from %d to %d\n", dis[q[i]], x, q[i]);
			ret += match[L-dist-1];
		}
	}
	for (int i = 0; i < tail; i++){
		pt = q[i]; dist = dis[pt];
		match[dist] = 0;
	}
	return ret;
}

int get(int root){
	int head = 0, tail = 0, res = n+1;
	fa[root] = 0;
	for (q[tail++] = root; head < tail; head++){
		int u = q[head];
		for (int t = en[u]; t != -1; t = e[t].n){
			int v = e[t].v;
			if (vis[v] || v == fa[u]) continue;
			fa[v] = u;
			q[tail++] = v;
		}
	}
	for (;tail; tail--){
		int u = q[tail-1], m = 0;
		sz[u] = 1;
		for (int t = en[u]; t != -1; t = e[t].n){
			int v = e[t].v;
			if (vis[v] || v == fa[u]) continue;
			sz[u] += sz[v];
			if (sz[v] > m) m = sz[v];
		}
		m = max(head-sz[u], m);
		if (res > m){
			res = m;
			root = u;
		}
	}
	return root;
}
int dc(int root){
	//get_size(root, 0);
	//root = get_root(root, 0, sz[root]).second;
	root = get(root);
	vis[root] = true;
	fa[root] = 0, dis[root] = 0, lha[root] = c[root], rha[root] = 0;
	//if(debug) printf("start from %d\n", root);
	int ret = go(root);
	//if (debug) puts("");
	for (int t = en[root]; t != -1; t = e[t].n){
		int v = e[t].v;
		if (vis[v]) continue;
	//	if (debug) printf("%d's subtree %d\n", root, v);
		ret -= go(v);
	}
	//if (debug)puts("");
	if (ret) return ret;
	for (int t = en[root]; t != -1; t = e[t].n){
		int v = e[t].v;
		if (vis[v]) continue;
		ret += dc(v);
		if (ret) return ret;
	}
	return ret;
}

int T;
int main()
{
	memset(match, 0, sizeof(match));
	dis[0] = -1; B[0] = 1;
	for (int i = 1; i < maxn; i++) B[i] = B[i-1] * seed;
	scanf("%d", &T); int cas = 0;
	while(T--){
		// scanf("%d", &n);
		read(n);
		init();
		for (int u, v, i = 1; i < n; i++){
//			scanf("%d %d", &u, &v);
			read(u), read(v);
			addedge(u, v);
			addedge(v, u);
		}
		scanf("%s", c+1); scanf("%s", s+1); L = strlen(s+1);
		pre[0] = suf[0] = 0;
		for (int i = 1, j = L; i <= L; i++, j--){
			pre[i] = pre[i-1] * seed + s[i];
			suf[i] = suf[i-1] * seed + s[j];
		}
		int ans = dc(1);
		printf("Case #%d: %s\n", ++cas, ans? "Find": "Impossible");
	}
	return 0;
}

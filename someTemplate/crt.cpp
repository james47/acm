//n个方程 x=a[i](mod m[i]) (0<=i<n)
LL china(int n, int* a, int *m){
	LL M = 1, d, y, x = 0;
	for (int i = 0; i < n; i++) M *= m[i];
	for (int i = 0; i < n; i++){
		LL w = M / m[i];
		gcd(m[i], w, d, d, y);
		x = (x + y*w*a[i]) % M; //小心乘法越界
	}
	return (x+M) % M;
}

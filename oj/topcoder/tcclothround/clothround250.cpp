#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

class SquareVerification{
public:
	int calculateCode(int x){
		int t = x * x;
		int ans = 0;
		while (t > 0){
			if (t % 10 > ans) ans = t % 10;
			t /= 10;
		}
		return ans;
	}
};

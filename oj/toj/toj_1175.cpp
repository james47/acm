#include<cstdio>
using namespace std;

bool isleap(int y)
{
	if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) return true;
	return false;
}

char Week[8][12] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int dayofmonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct Date{
	int y, m, d;
	Date(){}
	Date(int totday){
		if (totday > 639785) totday += 11;
		y = totday / 366;
		totday %= 366;
		totday += y - (y/4 - y/100 + y/400);
		y++;
		for (int &year = y;;year++){
			int del = 365 + isleap(year);
			if (totday > del) totday -= del;
			else break;
		}
		m = 1;
		for (int &month = m; month < 12; month++){
			int del = dayofmonth[month] + (month==2&&isleap(y));
			if (totday > del) totday -= del;
			else break;
		}
		d = totday;
	}
	Date(int _y, int _m, int _d): y(_y), m(_m), d(_d){}
	int totalday(){
		int leap = y/4 - y/100 + y/400;
		if (isleap(y)) leap --;
		int ret = (y-1) * 365 + leap;
		for (int i = 1; i < m; i++) ret += dayofmonth[i];
		if (isleap(y) && m > 2) ret++;
		ret += d;
		if (y > 1752) ret -= 11;
		else if (y == 1752 && m > 9) ret -= 11;
		else if (y == 1752 && m == 9 && d >= 14) ret -= 11;
		return ret;
	}
	int whatday(){
		int st = Date(1752, 9, 2).totalday(),
		    sum = totalday();
		int del = sum - st;
		if (del < 0) del = -del;
		del = (del % 7 + 3) % 7;
		if (del == 0) del = 7;
		return del;
	}
};

int main()
{
	int day;
	Date std = Date(2000, 1, 1);
	while(scanf("%d", &day))
	{
		if (day == -1) break;
		int sum = std.totalday() + day;
		Date ans = Date(sum);
		printf("%d-%02d-%02d %s\n", ans.y, ans.m, ans.d, Week[ans.whatday()]);
	}
}

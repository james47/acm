#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;

int trans(char x)
{
		if (x == 'C' || x == 'c')
				return 0;
		if (x == 'D' || x == 'd')
				return 1;
		if (x == 'E' || x == 'e')
				return 2;
		if (x == 'F' || x == 'f')
				return 3;
		return 0;
}
struct stack
{
		string dic[1010];
		int size;
		string sym;
		void push(string dd)
		{
				dic[size] = dd;
				size ++;
				return;
		}
		string pop(bool real)
		{
				string s = sym + ":";
				int tmp = 0;
				if (real && size > 0) size --;
				while (tmp < size)
				{
						s += "\\" + dic[tmp];
						tmp++;
				}
				return s;
		}
} disk[4];
int main()
{
		int m;
		string str;
		while (scanf("%d", &m) != EOF)
		{
				int currentdisk = 0;
				disk[0].sym = "C";
				disk[1].sym = "D";
				disk[2].sym = "E";
				disk[3].sym = "F";
				disk[0].size = 0;
				disk[1].size = 0;
				disk[2].size = 0;
				disk[3].size = 0;
				disk[0].push("users");
				disk[0].push("godle");
				while (m--)
				{
						cin >> str;
						if (str == "cd")
						{
								cin >> str;
								if (str == "..")
								{
										cout << disk[currentdisk].pop(true) << endl;
								}
								else
								{
										disk[currentdisk].push(str);
										cout << disk[currentdisk].pop(false) << endl;
								}
						}
						else
						{
								currentdisk = trans(str[0]);
								cout << disk[currentdisk].pop(false) << endl;
						}
				}
		}
		return 0;
}

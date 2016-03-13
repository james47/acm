#include<cstring>
#include<string>
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

map<pair<string, int>, int> M;
int cur, cnt;
struct DOC{
	string sub[30];
	int size, fa;
	int find(string);
	void push(string);
	void pop(string);
}doc[3000];
int DOC::find(string s)
{
	for (int i = 0; i < size; i++)
		if (sub[i] == s) return i;
	return -1;
}
void DOC::push(string s)
{
	if (find(s) != -1) return;
	doc[cnt].fa = cur;
	doc[cnt].size = 0;
	M[make_pair(s, cur)] = cnt ++;
	sub[size] = s;
	int p = size++;
	string tmp;
	while(p > 0 && sub[p] + sub[p-1] < sub[p-1] + sub[p]){
		tmp = sub[p];
		sub[p] = sub[p-1];
		sub[p-1] = tmp;
		p--;
	}
}
void DOC::pop(string s)
{
	int p = find(s);
	if (p == -1) return;
	size --;
	for (; p < size; p++)
		sub[p] = sub[p+1];
}
void init()
{
	M.clear();
	cur = cnt = 0;
	doc[cur].size = doc[cur].fa = 0;
	M[make_pair("/", 0)] = cnt++;
	doc[cur].push("home");
	cur = 1;
	doc[cur].push("brotherkai");
	cur = 2;
}
int main()
{
	init();
	string command;
	while(cin >> command)
	{
		if (command == "exit") break;
		if (command == "cd"){
			cin >> command;
			if (command == "/")
				cur = 0;
			else if (command == "..")
				cur = doc[cur].fa;
			else{
				if (M.find(make_pair(command, cur)) != M.end())
					cur = M[make_pair(command, cur)];
			}
		}
		else if (command == "rm"){
			cin >> command;
			cin >> command;
			doc[cur].pop(command);
		}
		else if (command == "ls"){
			for (int i = 0; i < doc[cur].size; i ++){
				if (i != 0) cout << ' ';
				cout << doc[cur].sub[i];
			}
			cout << endl;
		}
		else if (command == "mkdir"){
			cin >> command;
			doc[cur].push(command);
		}
	}
	return 0;
}

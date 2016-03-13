#include<cstring>
#include<string>
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int cnt, cur;
struct DOC{
	string sub[500];
	int fa, size;
	int sid[500];
	void push(string s);
	void pop(string s);
}doc[3000];
void DOC::push(string s)
{
	int i;
	for (i = 0; i < size; i++)
		if (s == sub[i]) break;
	if (i != size) return;
	doc[cnt].fa = cur;
	doc[cnt].size = 0;
	sid[size] = cnt++;
	sub[size++] = s;
	int p = size-1;
	string tmp;
	int tmpp;
	while(p > 0 && sub[p] + sub[p-1] < sub[p-1] + sub[p]){
		tmp = sub[p];
		sub[p] = sub[p-1];
		sub[p-1] = tmp;
		tmpp = sid[p];
		sid[p] = sid[p-1];
		sid[p-1] = tmpp;
		p--;
	}
}
void DOC::pop(string s)
{
	int p = 0;
	while(p < size && sub[p] != s) p++;
	if (p == size) return;
	size --;
	for (int i = p; i < size; i++){
		sub[p] = sub[p+1];
		sid[p] = sid[p+1];
	}
}
void init()
{
	cur = 0;
	cnt = 1;
	doc[cur].fa = 0;
	doc[cur].size = 0;
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
		if (command == "mkdir"){
			cin >> command;
			doc[cur].push(command);
		}
		else if (command == "cd"){
			cin >> command;
			if (command == "/")
				cur = 0;
			else if (command == "..")
				cur = doc[cur].fa;
			else{
				for (int i = 0; i < doc[cur].size; i++)
					if (doc[cur].sub[i] == command){
						cur = doc[cur].sid[i];
						break;
					}
			}
		}
		else if (command == "rm"){
			cin >> command;
			cin >> command;
			doc[cur].pop(command);
		}
		else if (command == "ls"){
			for (int i = 0; i < doc[cur].size; i++){
				if (i != 0) cout << ' ';
				cout << doc[cur].sub[i];
			}
			cout << endl;
		}
	}
	return 0;
}

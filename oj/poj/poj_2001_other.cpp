/*************************************************************************
    > File Name: poj_2001_other.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sun Jul 19 10:44:29 2015
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
char s[1005][25];
struct trie
{
    int val;string self;
    trie(){val=0;}
    map<char,trie>Data;
    void add(char *s){
    	// cout << self << endl;
        val++;
        if(s[0])  {Data[s[0]].self=self+s[0];Data[s[0]].add(s+1);}
    }
    string query(char *s){
        if(!s[0]||val==1)  return self;
        else  return Data[s[0]].query(s+1);
    }
}T;
int main()
{
    int n=0,i;
    while(scanf("%s",s[n])!=EOF)
        T.add(s[n++]);
    for(i=0;i<n;i++)
        printf("%s %s\n",s[i],T.query(s[i]).c_str());
    return 0;
}

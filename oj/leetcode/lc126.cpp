/*************************************************************************
    > File Name: lc126.cpp
    > Author: james47
    > Mail: 
    > Created Time: Thu Feb 25 22:36:13 2016
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        int size = 0;
        str2int[beginWord] = size ++;
        int2str.push_back(beginWord);
        str2int[endWord] = size ++;
        int2str.push_back(endWord);
        for (auto it = wordList.begin(); it != wordList.end(); it ++){
			if (*it != beginWord && *it != endWord){
				str2int[*it] = size ++;
				int2str.push_back(*it);
			}
        }
        
        edge.resize(size);
        /*
        for (int i = 0; i < size; i++)
            for (int j = i+1; j < size; j++){
                if (diff1(i, j)){
                    add_edge(i, j);
                }
            }
        */
        int len = beginWord.length();
        for (int i = 0; i < size; i++){
            for (int j = 0; j < len; j ++){
                string temp = int2str[i];
                char ch = int2str[i][j];
                for (char k = 'a'; k < 26 + 'a'; k++)
                    if (ch != k){
                        temp[j] = k;
                        if (str2int.find(temp) != str2int.end()){
                            add_edge(i, str2int[temp]);
                        }
                    }
            }
        }
        return bfs(0, 1, size);
    }

private:
    map<string, int> str2int;
    vector<string> int2str;
    vector<vector<int> > edge;
    const int inf = 1<<30;
    bool diff1(int x, int y){
        int len = int2str[x].length();
        int cnt = 0;
        for (int i = 0; i < len; i++){
            cnt += int2str[x][i] != int2str[y][i];
        }
        return cnt == 1;
    }
    
    void add_edge(int x, int y){
        edge[x].push_back(y);
    }
    vector<string> reverse(vector<string> &v){
        vector<string> ret;
        int size = v.size();
        for (int i = size-1; i >= 0; i--){
            ret.push_back(v[i]);
        }
        return ret;
    }
    
    vector<vector<string> > bfs(int st, int ed, int size){
        vector<vector<string> > res;
        vector<int> dis;
        dis.resize(size);
        for (int i = 1; i < size; i++) dis[i] = inf;
        vector<pair<int, int> > queue;
        queue.resize(size * 15);
        int head = 0, tail = 0;
        queue[tail ++] = make_pair(st, -1);
        while (head < tail){
            int cur = queue[head ++].first;
            if (cur == ed){
                vector<string> path;
                int pt = head - 1;
                while (pt != -1){
                    path.push_back(int2str[queue[pt].first]);
                    pt = queue[pt].second;
                }
                res.push_back(reverse(path));
                continue;
            }
            else if (dis[cur] > dis[ed]) break;
            int len = edge[cur].size();
            for (int i = 0; i < len; i++){
                int nxt = edge[cur][i];
                if (dis[cur] + 1 <= dis[nxt]){
                    dis[nxt] = dis[cur] + 1;
                    queue[tail ++] = make_pair(nxt, head - 1);
                }
            }
        }
        return res;
    }
};

int main()
{
	unordered_set<string> st;
	string s, b, e;
	cin >> b >> e;
	while (cin >> s){
		st.insert(s);
	}
	Solution sol;	
	sol.findLadders(b, e, st);
	return 0;
}

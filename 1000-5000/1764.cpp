#include <iostream>
#include <set>
//AC
//BOJ 1764 듣보잡
//https://www.acmicpc.net/problem/1764 
#include <string>
#include <vector>
using namespace std;
int main(){
	int n, m;
	string str;
	set<string> listen;
	set<string> see;
	vector<string> ls;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> str;
		listen.insert(str);
	}
	for(int i=0; i<m; i++){
		cin >> str;
		see.insert(str);
	}
	set<string> ::iterator it;
	set<string> ::iterator iter;
	int cnt = 0;
	for(it = listen.begin(); it!= listen.end(); it++){
		iter = see.find(*it);
		if(iter != see.end())	{
			cnt++;
			ls.push_back(*iter);
		}
	}
	cout << cnt << endl;
	for(int i=0; i<ls.size(); i++){
		cout << ls[i] << endl;
	}
}

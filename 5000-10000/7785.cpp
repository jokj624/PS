//AC
//BOJ 7785 회사에 있는 사람 
//https://www.acmicpc.net/problem/7785 
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n;
	string name, check;
	map<string, int, greater<string> > m;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> name >> check;
		if(check == "enter"){
			m[name] = 1;
		}
		else{
			m[name] = 0;
		}	
	}
	map<string, int> ::iterator it;
	for(it = m.begin(); it!=m.end(); it++){
		if(it->second == 1)	cout << it->first << "\n";
	}
	return 0;
}

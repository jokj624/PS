//AC 
//BOJ 20920 영단어 암기는 괴로워
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<string> v;
map<string, int> m; 
bool cmp(string &a, string &b){
	if(m[a] == m[b]){
		if(a.size() == b.size()){
			return (a.compare(b)<0);
		}
		else{
			return a.size() > b.size();
		}
	}
	else{
		return m[a] > m[b];
	}
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N, M;
	string s;
	cin >> N >> M;
	for(int i=0; i<N; i++){
		cin >> s;
		if(s.size() < M)	continue;
		if(m[s] == 0)	v.push_back(s);
		m[s] += 1;
	}
	sort(v.begin(), v.end(), cmp);
	for(string tmp : v){
		cout << tmp << "\n";
	}
	return 0;
}
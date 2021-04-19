//
//BOJ 1759 암호 만들기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<char> v;
int L, C;
void backTracking(string s, int moeum, int jaeum, int cur){
	if(s.size() == L && moeum >= 1 && jaeum >= 2){
		cout << s << '\n';
		return;
	}
	for(int i=cur; i<C; i++){
		if(v[i] == 'a' || v[i] == 'i' || v[i] == 'e' || v[i] == 'o' || v[i] == 'u'){
			s.push_back(v[i]);
			backTracking(s, moeum+1, jaeum, i+1);
			s.pop_back();
		}
		else {
			s.push_back(v[i]);
			backTracking(s, moeum, jaeum+1, i+1);
			s.pop_back();
		}
	}
}
int main(){
	char c;
	cin >> L >> C;
	for(int i=0; i<C; i++){
		cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	backTracking("", 0, 0, 0);
}
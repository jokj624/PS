//AC
//BOJ 1339 단어 수학
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
using namespace std;
vector<string> v;
map<int, int> m;
int arr[27];
bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}
int main(){
	int n, num = 9;
	cin >> n;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		v.push_back(s);
	}
	long long N = 0, sum = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<v[i].size(); j++){
			m[v[i][j]-'A'] += pow(10, v[i].size()-(j+1));
		}
	}
	vector<pair<int,int>> vec( m.begin(), m.end() );
	sort(vec.begin(), vec.end(), cmp);
	for(int i=0; i<vec.size(); i++){
		arr[vec[i].first] = num;
		num -= 1;
	}
	for(int i=0; i<n; i++){
		N = 0;
		for(int j=0; j<v[i].size(); j++){
			N += (arr[v[i][j]-'A'] * pow(10, v[i].size()-(j+1)));
		}
		sum += N;
	}	
	cout << sum;
	return 0;
}

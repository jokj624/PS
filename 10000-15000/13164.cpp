//AC
//BOJ 13164 행복 유치원
//www.acmicpc.net/problem/13164 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n, k, a, ans=0;
	cin >> n >> k;
	vector<int> v;
	vector<int> dif;
	for(int i=0; i<n; i++){
		scanf("%d", &a);
		v.push_back(a);
	}
	for(int i=0; i<n-1; i++){
		dif.push_back((v[i+1]-v[i]));
	}
	sort(dif.begin(), dif.end());
	for(int i=0; i<(n-k); i++){
		ans += dif[i];
	}
	cout << ans;
	return 0;
}

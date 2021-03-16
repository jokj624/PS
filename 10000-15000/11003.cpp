//AC 
//BOJ 11003 최솟값 찾기 
//https://www.acmicpc.net/problem/11003

#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main(){
	int n, l; 
	cin >> n >> l;
	deque<pair<int,int> > d;
	vector<int> ans(n);
	int a[n+1];
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<n; i++){
		int cur = a[i];
		if(!d.empty() && d.front().second<=i-l){
			d.pop_front();
		}
		while(!d.empty()&&d.back().first> cur){
			d.pop_back();
		}
		d.push_back(make_pair(cur, i));
		ans[i] = d.front().first;
		printf("%d ", ans[i]);
	}
	return 0;
	
}

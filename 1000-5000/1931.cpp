
//AC
//BOJ 1931 회의실 배정 
//https://www.acmicpc.net/problem/1931

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> time;
vector<time> room;
bool cmp(const time &x, const time &y){
	if(x.second == y.second){
		return x.first < y.first;
	}
	else	return x.second < y.second;
}
int main(){
	int n, ans=1, idx=0;
	cin >> n;
	for(int i=0; i<n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		room.push_back({a, b});
	}
	sort(room.begin(), room.end(), cmp);
	for(int i=1; i<n; i++){
		if(room[i].first >= room[idx].second){
			ans+=1;
			idx = i;
		}
	}
	cout << ans << "\n";
	return 0;
}  

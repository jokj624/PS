//AC
//BOJ 2109 순회강연
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> lec;

bool cmp(const lec &a, const lec &b){
	if(a.second == b.second){
			return a.first<b.first;
		}
		else{
			return a.second<b.second;
		}
}
priority_queue<int> pq;
vector<lec> day;
int main(){
	int n, p, d, ans = 0, cur = 0, idx;
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d %d", &p, &d);
		day.push_back({p, d});
		cur = max(cur, d);
	}
	sort(day.begin(), day.end(), cmp);
	idx = n-1;
	while(cur){
		while(idx < n && day[idx].second == cur){
			pq.push(day[idx--].first);
		}
		if(!pq.empty()){
			ans += pq.top();
			pq.pop();
		}
		cur-=1;
	}
	cout << ans;
	return 0;
}
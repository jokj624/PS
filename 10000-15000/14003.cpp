//AC
//BOJ 14003 가장 긴 증가하는 부분 수열 5
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define INF -1100000000
using namespace std;
vector<int> lis;
vector<pair<int, int> > pre;
stack<int> ans;
int main(){
	int N, a, index = 0, curIdx = 0;
	cin >> N;
	for(int i=0; i<N; i++){
		scanf("%d", &a);
		if(lis.empty()){
			lis.push_back(a);
			pre.push_back({a, i});
			continue;
		}
		if(lis[index] < a){
			lis.push_back(a);
			pre.push_back({a, ++index});
			curIdx = max(curIdx, index);
		}
		else{
			int idx = lower_bound(lis.begin(),lis.end(), a)-lis.begin();
			lis[idx] = a;
			pre.push_back({a, idx});
			curIdx = max(curIdx, idx);
		}	
	}

	for(int i=pre.size()-1; i>=0; i--){
		if(pre[i].second == curIdx){
			ans.push(pre[i].first);
			curIdx-=1;
		}
	}
	printf("%d\n", ans.size());
	while(!ans.empty()){
		printf("%d ", ans.top());
		ans.pop();
	}
	return 0;
}
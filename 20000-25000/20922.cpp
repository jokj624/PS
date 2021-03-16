//AC
//BOJ 20922 겹치는 건 싫어

#include <iostream>
#include <deque>
using namespace std;
deque<int> dq;
int count[101010];
int main(){
	int N, K, a, cnt=0, ans=0;
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		scanf("%d", &a);
		count[a]++;
		if(dq.empty()){
			dq.push_back(a);
		}
		else{
			if(count[a] <= K){
				dq.push_back(a);
			}
			else{
				int tmp = -1;
				while(tmp != a && !dq.empty()){
					tmp = dq.front();
					dq.pop_front();
					count[tmp] -= 1;
				}
				dq.push_back(a);
			}
		}
		cnt = dq.size();
  		ans = max(ans,cnt);
	}
	printf("%d", ans);
	return 0;
}
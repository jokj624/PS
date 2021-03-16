//AC
//BOJ 1516 게임 개발
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int ind[501];
int ans[501];
int c[501];
vector<int> v[501];
void topo(int N){
	queue<int> q;
	for(int i=1; i<=N; i++){
		if(ind[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int x = q.front();
		c[x] = ans[x];
		q.pop();
		for(int y : v[x]){
			ind[y] -= 1;
			ans[y] = max(ans[y], c[y]+ans[x]);
			if(ind[y] == 0){
				q.push(y);
			}
			
		}
	}
}
int main(){
	int N, t;
	cin >> N;
	for(int i=1; i<=N; i++){
		scanf("%d", &c[i]);
		ans[i] = c[i];
		while(1){
			scanf("%d", &t);
			if(t==-1)	break;
			v[t].push_back(i);
			ind[i]++;
		}
	}
	topo(N);
	for(int i=1; i<=N; i++){
		printf("%d\n", ans[i]);
	}	
	return 0;
}
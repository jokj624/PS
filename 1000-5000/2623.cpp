//AC
//BOJ 2623 음악 프로그램
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> music[1010];
vector<int> ans;
int ind[1010];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int t, cur, prev; 
		scanf("%d", &t);
		for(int i=0; i<t; i++){
			scanf("%d", &cur);
			if(i==0){
				prev = cur;
			}
			else{
				music[prev].push_back(cur);
				ind[cur]++;
				prev = cur;
			}
		}
	}
	queue<int> q;
	for(int i=1; i<=n; i++){
		if(ind[i] == 0){
			q.push(i);
		}
	}
	for(int i=1; i<=n; i++){
		if(q.empty()){
			printf("0\n");
			return 0;
		}
		int x = q.front();
		q.pop();
		ans.push_back(x);
		for(int y : music[x]){
			ind[y]--;
			if(ind[y]==0){
				q.push(y);
			}
		}
	}
	for(int sing : ans){
		printf("%d\n", sing);
	}
	return 0;
}
//AC
//BOJ 9372 상근이의 여행 
// https://www.acmicpc.net/problem/9372
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, cnt=0;
vector<int> air[1001];	
void bfs(int start){
	queue<int> q;
	int visit[1001] = {0};
	q.push(start);
	visit[start] = 1;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=0; i<air[x].size(); i++){
			int y = air[x][i];
			if(!visit[y]){
				q.push(y);
				visit[y] = 1;
				cnt++;
			}
		}
	}
}
int main(){
	int t, a,b, max_cnt=10000000;
	cin >> t;
	while(t--){
		scanf("%d %d", &n, &m);
		for(int i=0; i<m; i++){
			scanf("%d %d",&a,&b);
			air[a].push_back(b);
			air[b].push_back(a);
		}
		for(int i=1; i<=n; i++){
			bfs(i);
			max_cnt=min(cnt, max_cnt);
		}
		for(int i=1; i<=n; i++){
			air[i].clear();
		}
		printf("%d\n", max_cnt);
		max_cnt=10000000;	cnt=0;
	}
	return 0;
}

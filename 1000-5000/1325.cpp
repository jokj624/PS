//AC
//BOJ 1325 효율적인 해킹 
//https://www.acmicpc.net/problem/1325 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> com[10001];
int n, m, cnt=0;
void bfs(int start){
	queue<int> q;
	int visit[10001]={0};
	visit[start] = 1;
	q.push(start);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=0; i<com[x].size(); i++){
			int y = com[x][i];
			if(!visit[y]){
				q.push(y);
				visit[y] = 1;
				cnt++;
			}
		}
	}
}
int main(){
	int arr[10001]={0};
	scanf("%d %d", &n, &m);
	int x, y, max2=0;
	for(int i=0; i<m; i++){
		scanf("%d %d", &x, &y);
		com[y].push_back(x);
	}
	for(int i=1; i<=n; i++){
		if(!com[i].empty()){
			bfs(i);
			arr[i] = cnt;
			cnt = 0;
		}
	}
	for(int i=1; i<=n; i++){
		max2 = max(arr[i], max2);
	}
	for(int i=1; i<=n; i++){
		if(max2 == arr[i])	printf("%d ", i);
	}
	return 0;
}

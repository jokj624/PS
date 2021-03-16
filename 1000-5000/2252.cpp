//AC
//BOJ 2252 줄 세우기 
//https://www.acmicpc.net/problem/2252 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 32001
vector<int> compare[MAX];
int ind[MAX]={0};
void topology(int n){
	queue<int> q;
	for(int i=1; i<=n; i++){
		if(ind[i]==0)
			q.push(i);
	}
	for(int i=1; i<=n; i++){
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for(int j=0; j<compare[x].size(); j++){
			int y = compare[x][j];
			ind[y]--;
			if(ind[y]==0){
				q.push(y);
			}
		}
	}
}
int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		compare[a].push_back(b);
		ind[b]++;
	}
	topology(n);
	return 0;
}

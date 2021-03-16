//AC
//BOJ 1766 문제집 
//https://www.acmicpc.net/problem/1766 
#include <iostream>
#include <queue>
#include <vector>
#define MAX 32001
using namespace std;
vector<int> problem[MAX];
int ind[MAX]={0};
void topology(int n){
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i=1; i<=n; i++){
		if(ind[i]==0){
			pq.push(i);
		}
	}
	for(int i=1; i<=n; i++){
		int x = pq.top();
		pq.pop();
		printf("%d ", x);
		for(int j=0; j<problem[x].size(); j++){
			int y = problem[x][j];
			ind[y]--;
			if(ind[y]==0){
				pq.push(y);
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
		problem[a].push_back(b);
		ind[b]++;
	}
	topology(n);
	return 0;
}

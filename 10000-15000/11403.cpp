//AC
//BOJ 11403 경로 찾기 
//https://www.acmicpc.net/problem/11403 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int arr[101][101]={0};
int n;
void bfs(int start){
	queue<int> q;
	int visit[101]={0};
	q.push(start);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=0; i<n; i++){
			if(!visit[i] && arr[x][i]==1){
				q.push(i);
				visit[i] = 1;
				arr[start][i] = 1;
			}
		}
	}
}
int main(){
	cin >> n;
	int m;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &m);
			if(m==1){
				arr[i][j] = 1;
			}
		}
	}
	for(int i=0; i<n; i++){
		bfs(i);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d ", arr[i][j]);
			if(j==n-1)	printf("\n");
		}
	}
}

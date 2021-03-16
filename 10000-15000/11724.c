//AC
//BOJ 11724 연결 요소의 개수 
//https://www.acmicpc.net/problem/11724 
#include <stdio.h>
#define MAX 1002
int graph[MAX][MAX] = {0,};
int visit[MAX]={0};
int vertex, edge;
int DFS(int v);
int main(){
	int cnt=0;
	int i, a,b;
	scanf("%d %d\n", &vertex, &edge);
	for(i=0; i<edge; i++){
		scanf("%d %d", &a, &b);
		graph[a][b]= 1;
		graph[b][a]= 1;
	}
	for(i=1; i<=vertex; i++){
		if(!visit[i]){
			DFS(i);
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
int DFS(int v){
	int i;
	visit[v] = 1;
	for(i=1; i<=vertex; i++){
		if(graph[v][i]){
			if(!visit[i]) 	DFS(i);
		}
	}
	return;
}

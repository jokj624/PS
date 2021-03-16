//AC
//BOJ 1260 DFS와 BFS
//https://www.acmicpc.net/problem/1260
#include <stdio.h>
#define MAX 1002
int graph[MAX][MAX] = {0,};
int visit[MAX]={0};
int bvisit[MAX]={0};
int queue[MAX];
int vertex, edge;
int DFS(int v);
int BFS(int v);
int main(){
	int i, v, a, b;
	scanf("%d %d %d", &vertex, &edge, &v);
	for(i=0; i<edge; i++){
		scanf("%d %d", &a, &b);
		graph[a][b]= 1;
		graph[b][a]= 1;
	}
	DFS(v);
	printf("\n");
	BFS(v);
}
int DFS(int v){
	int i;
	visit[v] = 1;
	printf("%d ", v);
	for(i=1; i<=vertex; i++){
		if(graph[v][i]){
			if(!visit[i]) 	DFS(i);
		}
	}
	return;
}
int BFS(int v){
	int front =0 , rear=0, i;
	printf("%d ", v);
	queue[0] = v;
	rear++;
	bvisit[v] = 1;
	while(front<rear){
		v = queue[front++];
		for(i=1; i<=vertex; i++){
			if(graph[v][i]){
				if(!bvisit[i]){
					printf("%d ", i);
					queue[rear++] = i;
					bvisit[i] = 1;
				}
			}
		}
	}
	return;
}

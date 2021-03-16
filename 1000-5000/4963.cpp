//AC
//BOJ 4963 섬의 개수 
//https://www.acmicpc.net/problem/4963 
#include <iostream>
#include <string.h>
using namespace std;
int land[51][51]={0};
int visit[51][51]={0};
int dx[8] = {-1,1,0,0,-1,1,-1,1};
int dy[8] = {0,0,-1,1,-1,-1,1,1};
int w,h, cnt=0;
void dfs(int x, int y){
	visit[x][y] = 1;
	for(int i=0; i<8; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx>=0 && nx<h && ny>=0 && ny<w){
			if(!visit[nx][ny] && land[nx][ny]==1){
				dfs(nx,ny);
			}
		}
	}
}
int main(){
	do{
		scanf("%d %d", &w, &h);
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				scanf("%d", &land[i][j]);
			}
		}
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(!visit[i][j] && land[i][j]==1){
					dfs(i,j);
					cnt++;
				}
			}
		}	
		if(w!=0 || h!=0)	printf("%d\n", cnt);
		memset(visit,0,sizeof(visit));
		memset(land,0,sizeof(land));
		cnt=0;
	}while(w!=0 || h!=0);
	return 0;
}

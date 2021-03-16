//AC
//BOJ 1012 유기농배추 
//https://www.acmicpc.net/problem/1012

癤?include <iostream>
#include <string.h>
using namespace std;
int baechu[51][51] = {0};
int visit[51][51] = {0};
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int cnt = 0, n, m;
void dfs(int s, int e){
	visit[s][e] = 1;
	for(int i=0; i<4; i++){
		int nx = s+dx[i];
		int ny = e+dy[i];
		if(nx>=0 && nx < n && ny >= 0 && ny < m){
			if(!visit[nx][ny] && baechu[nx][ny] == 1){
				dfs(nx, ny);
			}
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int k,r,c;
		scanf("%d %d %d",&m,&n,&k);
		for(int i=0; i<k; i++){
			scanf("%d %d", &r, &c);
			baechu[c][r] = 1;
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(!visit[i][j] && baechu[i][j] == 1){
					dfs(i,j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
		memset(visit, 0, sizeof(visit));
		memset(baechu, 0, sizeof(baechu));
	}
	return 0;
}

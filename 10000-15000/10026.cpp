//AC
//BOJ 10026 적록색약 
//https://www.acmicpc.net/problem/10026 
#include <iostream>
using namespace std;

char color[101][101];
bool visit[101][101]={false};
int n;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int p,int q, char c){
	visit[p][q] = true;
	for(int i=0; i<4; i++){
		int nextx = p+dx[i];
		int nexty = q+dy[i];
		if(nextx >= 0 && nextx < n && nexty >=0 && nexty <n){
			if(!visit[nextx][nexty] && c == color[nextx][nexty]){
				dfs(nextx, nexty, color[nextx][nexty]);
			}
		}
	}
}
int all(){
	int cnt = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!visit[i][j]){
				dfs(i,j,color[i][j]);
				cnt++;
			}
		}
	}
	return cnt;
}
int main(){
	int count1, count2;
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%s", &color[i]);
	}
	count1 = all();
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			visit[i][j] = false;
			if(color[i][j] == 'G')	color[i][j] = 'R';
		}
	}
	count2 = all();
	
	cout << count1 << " " << count2;
}

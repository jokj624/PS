//AC
//BOJ 1987 알파벳 
//https://www.acmicpc.net/problem/1987

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char arr[22][22];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int r, c, ans=1;
bool visit[28];
void dfs(int x,int y, int res){
	ans = max(ans, res);
	for(int i=0; i<4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx>r || ny>c || nx<=0 || ny<=0)	continue;
		char ch = arr[nx][ny];
		if(!visit[ch-'A']){
			visit[ch-'A'] = true;
			dfs(nx, ny, res+1);
			visit[ch-'A'] = false;
		}
	}
	return;
}
int main(){
	cin >> r >> c;
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			cin >> arr[i][j];
		}
	}
	char ch = arr[1][1];
	visit[ch-'A']=true;
	dfs(1,1,1);
	cout << ans <<"\n";
	return 0;
}

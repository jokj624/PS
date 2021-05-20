//AC
//BOJ 1103 게임
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string map[105];
int dp[105][105];
bool visit[105][105];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int N, M;
int dfs(int x, int y){
	if(x < 0 || y < 0 || x >= N || y >= M)	return 0;
	if(map[x][y] == 'H')	return 0;
	if(visit[x][y]){
		printf("-1");
		exit(0);
	}
	if(dp[x][y])	return dp[x][y];
	visit[x][y] = true;
	for(int i=0; i<4; i++){
		int nx = x + dx[i]*(map[x][y]-'0');
		int ny = y + dy[i]*(map[x][y]-'0');
		dp[x][y] = max(dp[x][y], dfs(nx, ny)+1);
	}
	visit[x][y] = false;
	return dp[x][y];
}
int main(){
	cin >> N >> M;
	for(int i=0; i<N; i++){
		cin >> map[i];
	}
	cout << dfs(0, 0);
	return 0;
}

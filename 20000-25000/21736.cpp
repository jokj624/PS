//AC
//SMUPC-C번
//BOJ 21736 헌내기는 친구가 필요해
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string s[602];
int visit[602][602];
int main(){
	int N, M;
	int ans = 0;
	cin >> N >> M;
	for(int i=0; i<N; i++){
		cin >> s[i];
	}
	queue<pair<int, int> > q;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(s[i][j] == 'I'){
				q.push({i, j});
				visit[i][j] = 1;
			}
		}
	}
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx >= N || ny >= M)	continue;
			if(s[nx][ny] == 'P' && !visit[nx][ny]){
				ans += 1;
				visit[nx][ny] = 1;
				q.push({nx, ny});
			}
			else if(s[nx][ny] == 'O' && !visit[nx][ny]){
				q.push({nx, ny});
				visit[nx][ny] = 1;
			}
		}
	}
	if(ans == 0)	cout << "TT";
	else cout << ans;
	return 0;
}

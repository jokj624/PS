//AC
//BOJ 16441 아기돼지와 늑대
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
string map[105];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool visit[105][105];
void bfs(int N, int M) {
	queue<pair<int, int> > q;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j] == 'W'){
				q.push({i, j});
				visit[i][j] = true;
			}
		}
	}
	while(!q.empty()){
		pair<int, int> cur = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if(nx < 0 || ny < 0 || nx >= N || ny >= M)	continue;
			if(visit[nx][ny])	continue;
			if(map[nx][ny] == '.'){
				q.push({nx, ny});
				visit[nx][ny] = true; //초원
			}
			else if(map[nx][ny] == '+'){
				while(map[nx][ny] != '#' && map[nx][ny] != '.'){
					nx += dx[i];
					ny += dy[i];
				}
				if(map[nx][ny] == '#')	{
					nx -= dx[i];	ny -= dy[i];
				}
				if(!visit[nx][ny]){
					visit[nx][ny] = true;
					q.push({nx, ny});
				}
		
			}
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(!visit[i][j] && map[i][j] == '.'){
				printf("P");
			}
			else	cout << map[i][j];
		} printf("\n");
	}
}
int main(){
	int N, M, x, y;
	cin >> N >> M;
	for(int i=0; i<N; i++){
		cin >> map[i];
	}
	bfs(N, M);
	return 0;
}

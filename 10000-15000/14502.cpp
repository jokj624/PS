//AC
//BOJ 14502 연구소
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, ans = 0;
int map[10][10];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int bfs(int bfsmap[][10]){
	queue<pair<int, int> > q;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
		//	printf("%d ", bfsmap[i][j]);
			if(bfsmap[i][j] == 2)	q.push({i, j});
		}
	}
	while(!q.empty()){
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx = a + dx[i];
			int ny = b + dy[i];
			if(nx < 0 || ny < 0 || nx >= N || ny >= M)	continue;
			if(bfsmap[nx][ny] == 0){
				bfsmap[nx][ny] = 2;
				q.push({nx, ny});
			}
		}
	}
	int cnt = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(bfsmap[i][j] == 0)	cnt += 1;
		}
	}
	return cnt;
}
int wallDfs(int wall, int x, int y, int arr[][10]){
	if(wall == 3){
		int tmpmap[10][10];
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				tmpmap[i][j] = arr[i][j];
			}
		}
		return bfs(tmpmap);
	}
	for(int i = x; i<N; i++){
		for(int j=0; j<M; j++){
			if(arr[i][j] == 0){
				arr[i][j] = 1;
				ans = max(ans, wallDfs(wall+1, i, j, arr));
				arr[i][j] = 0;
			}
		}
	}
	return ans;
}
int main(){
	int res = 0;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d", &map[i][j]);
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j] == 0){
				map[i][j] = 1;
				res = max(res,wallDfs(1, i, j, map));
				map[i][j] = 0;
			}
		}
	}
	printf("%d", res);
	return 0;
}

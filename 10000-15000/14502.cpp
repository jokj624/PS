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
			if(bfsmap[i][j] == 2)	q.push({i, j});  // 초기 바이러스 위치 저장
		}
	}
	while(!q.empty()){
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx = a + dx[i];
			int ny = b + dy[i];
			if(nx < 0 || ny < 0 || nx >= N || ny >= M)	continue;   // 경계선 예외 처리
			if(bfsmap[nx][ny] == 0){    // 해당 위치 0이고 도달 가능하면 바이러스로 바꿔준다.
				bfsmap[nx][ny] = 2;  
				q.push({nx, ny});
			}
		}
	}
	int cnt = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(bfsmap[i][j] == 0)	cnt += 1;   // 바이러스 도달 못한 곳 카운팅
		}
	}
	return cnt;  // 해당 탐색에서 결과 반환
}
int wallDfs(int wall, int x, int y, int arr[][10]){
	if(wall == 3){    // wall 3개면 바로 bfs로 바이러스 뿌리기 시작한다
		int tmpmap[10][10];
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				tmpmap[i][j] = arr[i][j];   // bfsmap 배열에 보낼 copy 배열 생성 
			}
		}
		return bfs(tmpmap);   
	}
	for(int i = x; i<N; i++){   // 가로 행 이전은 모두 이전에 했었으니 x행 부터 시작
		for(int j=0; j<M; j++){
			if(arr[i][j] == 0){
				arr[i][j] = 1;   // 벽 1개 만들고 
				ans = max(ans, wallDfs(wall+1, i, j, arr));   // 재귀로 벽 1개 더 생성
				arr[i][j] = 0;   // 벽 원래대로 
			}
		}
	}
	return ans;  // 정답 반환
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
				map[i][j] = 1;  // 첫 벽 1개 생성
				res = max(res,wallDfs(1, i, j, map));   // 이어서 벽 만들고 반환된 정답 비교
				map[i][j] = 0;   // 첫번째로 만든 벽 원래대로
			}
		}
	}
	printf("%d", res); 
	return 0;
}

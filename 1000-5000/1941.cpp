//미완성
//BOJ 1941 소문난 칠공주

#include <iostream>
#include <queue>
#include <string>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
string arr[6];
bool visit[6][6];
int ans = 0;
queue<pair<int, int> > q;
void backTracking(int x, int y, int curS, int curY){
	if(curS + curY == 7){
		ans += 1;
		return;
	}
	q.push({x, y});
	while(!q.empty()){
		int fir = q.front().first;
		int sec = q.frotn().second;
	}
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx > 4 || ny > 4){
			continue;
		}
		if(!visit[nx][ny]){
			if(arr[nx][ny] == 'S'){
				visit[nx][ny] = true;
				backTracking(nx, ny, curS+1, curY);
				visit[nx][ny] = false;
			}
			else if(arr[nx][ny] == 'Y' && curY < 3) {
				visit[nx][ny] = true;
				backTracking(nx, ny, curS, curY+1);
				visit[nx][ny] = false;
			}
		} 
	}
	
}
int main(){
	for(int i=0; i<5; i++){
		cin >> arr[i];
	}
//	for(int i=0; i<5; i++){
//		for(int j=0; j<5; j++){
//			cout << arr[i][j] << " ";
//		}
//		cout << endl;
//	}
	visit[0][0] = true;
	backTracking(0, 0, 0, 0);
	cout << ans;
	return 0;
}
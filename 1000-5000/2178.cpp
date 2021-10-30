//AC
//BOJ 2178 미로탐색
#include <iostream>
#include <queue>
using namespace std;
int arr[101][101];
int cnt[101][101];
bool visit[101][101] = {false};
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int n, m;
queue<pair<int, int> > q;
void bfs(int x, int y){
	q.push({x,y});
	visit[x][y] = true;
	cnt[x][y] = 1;
	while(!q.empty()){
		int x2 = q.front().first;
		int y2 = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx = x2 + dx[i];
			int ny = y2 + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m){
				continue;
			}
			if(!visit[nx][ny] && arr[nx][ny] == 1){
				visit[nx][ny] = true;
				cnt[nx][ny] = cnt[x2][y2] + 1;
				q.push({nx, ny});
			}
		}
	}
}
int main(){
	cin >> n >> m;
	char ch[101];
	for(int i=0; i<n; i++){
		scanf("%s", ch);
		for(int j=0; j<m; j++){
			arr[i][j] = ch[j] - '0';
			ch[j] = '\0';
		}
	}
	bfs(0,0);
	cout << cnt[n-1][m-1];
	return 0;
}

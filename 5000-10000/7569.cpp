//AC
//BOJ 7569 토마토
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define SIZE 101
using namespace std;
int day[SIZE][SIZE][SIZE];
int tomato[SIZE][SIZE][SIZE];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int dh[2] = { 1, -1 };
struct Index{
	int h, m, n;
};
int main(){
	int M, N, H;
	queue<Index> q;
	cin >> N >> M >> H;
	int tmp = 0;
	while(tmp < H){
		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				day[tmp][i][j] = -1;
				scanf("%d", &tomato[tmp][i][j]);
				if(tomato[tmp][i][j] == 1){
					day[tmp][i][j] = 0;
					q.push({tmp, i, j});
				}
			}
		}
		tmp += 1;
	}
	while(!q.empty()){
		int h1 = q.front().h;
		int m1 = q.front().m;
		int n1 = q.front().n;
		q.pop();
		for(int i=0; i<4; i++){
			int nx = m1+dx[i];
			int ny = n1+dy[i];
			if(nx < 0 || ny < 0 || nx >= M || ny >= N)	continue;
			if(tomato[h1][nx][ny] == 0 && day[h1][nx][ny] == -1){
				day[h1][nx][ny] = day[h1][m1][n1] + 1;
				q.push({h1, nx, ny});
			}
		}
		for(int i=0; i<2; i++){
			int nh = h1+dh[i];
			if(nh < 0 || nh >= H)	continue;
			if(!tomato[nh][m1][n1] && day[nh][m1][n1] == -1){
				day[nh][m1][n1] = day[h1][m1][n1] + 1;
				q.push({nh, m1, n1});
			}
		}
	}
	int ans = 0;
	for(int i=0; i<H; i++){
		for(int j=0; j<M; j++){
			for(int k=0; k<N; k++){
				ans = max(ans, day[i][j][k]);
				if(day[i][j][k] == -1 && !tomato[i][j][k]){
					printf("-1");
					return 0;
				}
			}
		}		
	}
	printf("%d" , ans);
	return 0;
}

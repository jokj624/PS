//AC
//BOJ 7576 토마토 
//https://www.acmicpc.net/problem/7576 
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
queue<pair<int,int>> tomatos;
int box[1001][1001];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int n,m;
int total=0;
int bfs();
int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> box[i][j];
			if(box[i][j] == 1)
				tomatos.push(make_pair(i,j));	//큐 안에 이미 익어있는 애들 삽입 
			else if(box[i][j] == -1)	total++;	//나중에 총합 세려고 빈  토마토 개수 셈  
		}
	}
	cout << bfs();
	return 0; 
} 
int bfs(){
	pair<int, int> now;
	int size, days=0, nextx, nexty;
	while(!tomatos.empty()){
		size = tomatos.size();
		total+=size;
		if(total == n*m)	return days;	//total이 모든 토마토 수가 되었을 때 (비어있는 칸 포함) 
		for(int i=0; i<size; i++){
			now = tomatos.front();
			tomatos.pop();
			for(int j=0; j<4; j++){
				nextx = now.first + dx[i];
				nexty = now.second + dy[i];
				if(nextx < m && nexty < n){
					if(nextx >= 0 && nexty >= 0){
						if(box[nextx][nexty] == 0){
							box[nextx][nexty] = 1;
							tomatos.push(make_pair(nextx,nexty));
						}				
					}
				}
			}
		}
		days++;
	}
}

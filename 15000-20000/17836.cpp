//AC
//BOJ 17836 공주님을 구해라! 
//https://www.acmicpc.net/problem/17836
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
typedef struct{
	int x1;
	int y1;
	int gram1;
	int time1;
}a;
int arr[105][105];
int d[105][105][2];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<a> q;
int n, m, t;
int main(){
	cin >> n >> m >> t;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	d[1][1][0] = 0;
	q.push({1,1,0,0});
	while(!q.empty()){
		int x, y, gram, time;
		x=q.front().x1;
		y=q.front().y1;
		gram = q.front().gram1;
		time = q.front().time1;
		q.pop();
		if(x==n && y==m){
			printf("%d", d[x][y][gram]);
			return 0;
		}
		if(arr[x][y] == 2){
			gram = 1;
			d[x][y][gram] = time; 
		}
		if(time > t){
			continue;
		}
		for(int i=0; i<4; i++){
			int nextx = dx[i] + x;
			int nexty = dy[i] + y;	
			if(nextx>n || nexty>m || nexty<=0 || nextx<=0){
				continue;
			}
			if(d[nextx][nexty][gram]>0){
				continue;
			}
			if(gram==1){
				d[nextx][nexty][gram] = time+1;
				q.push({nextx, nexty, gram, time+1});
			}
			else{
				if(arr[nextx][nexty]!=1){
					d[nextx][nexty][gram] = time+1;
					q.push({nextx, nexty, gram, time+1});
				}
			}
		}	
	}
	printf("Fail");
	return 0;
} 

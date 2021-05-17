//AC
//BOJ 18405 경쟁적 전염
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int arr[202][202];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};  //상하좌우 좌표 배열
struct Virus{
	int virus;
	int x;
	int y;
};   //Virus 구조체, 종류, 위치 정보 담는다.
bool cmp(const Virus& v1, const Virus& v2){
	return v1.virus < v2.virus;
}   // virus 종류가 낮은 것 부터 정렬
int main(){
	vector<Virus> vec;
	int N, K, S, X, Y;
	scanf("%d %d", &N, &K);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &arr[i][j]);
			if(arr[i][j] >= 1 && arr[i][j] <= K){
				vec.push_back({arr[i][j], i, j});   // 바이러스 정보 push 
			}
		}
	}
	scanf("%d %d %d", &S, &X, &Y);
	int s = 0;
	sort(vec.begin(), vec.end(), cmp); //처음 들어온 바이러스 낮은 번호부터 오도록 정렬
	while(s < S){  // 초가 아직 S에 도달하지 못했다면
		int len = vec.size();
		for(int j=0; j<len; j++){
			Virus v = vec[j];
			for(int i=0; i<4; i++){
				int nx = v.x + dx[i];
				int ny = v.y + dy[i];   
				if(nx <= 0 || ny <= 0 || nx > N || ny > N)	continue;  //경계선 예외 처리
				if(!arr[nx][ny]){
					arr[nx][ny] = v.virus;  // 바이러스 채우기
					vec.push_back({arr[nx][ny], nx, ny});
				}
			}
		}
		if(arr[X][Y] > 0)	break;  // s < S 일 때, 이미 채워졌다면 더 이상 볼 필요 없다. 
		s++;  //1초 증가시킨다
	}
	printf("%d", arr[X][Y]);
	return 0;
}

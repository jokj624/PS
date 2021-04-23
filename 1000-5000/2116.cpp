//AC
//BOJ 2116 주사위 쌓기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dice[10001][7];
int front[7];
int main(){
	int n, num;
	int ans = 0, sum = 0, maxN = 0, idx, std;
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=6; j++){
			scanf("%d", &dice[i][j]);
		}
	}
	front[1] = 6;
	front[2] = 4;
	front[3] = 5;
	front[4] = 2;
	front[5] = 3;
	front[6] = 1;  
	for(int i=1; i<=6; i++){
		sum = 0;	maxN = 0;
		// 1번 주사위에서 i번을 첫번째로 고름
		// 서로 마주 보는 위치	  1	- 6, 2-4 , 3-5
		for(int p = 1; p <= 6; p++){
			if(p != dice[1][i] && p != dice[1][front[i]]){
				maxN = max(maxN, p);
			}
		}
		sum += maxN;
		std = dice[1][i];	//1번째 top
		for(int j=2; j<=n; j++){
			maxN = 0;
			for(int x = 1; x <= 6; x++){
				if(dice[j][x] == std){
					idx = x;	//다음 주사위에서 이전 top 위치 알아내기
					break;
				}
			}
			int top = dice[j][front[idx]];	//다음 주사위에서 이전 top과 마주보고 있던 수가 top이 됨
			int bottom = std;   //다음 주사위에서 이전 top은 bottom이 됨
			for(int k=1; k<=6; k++){
				if(k != top && k != bottom)		maxN = max(maxN, k);   //옆면에 올 수 있는 수 중 가장 큰 수 고르기
			}
			sum += maxN;
			std = top;
		}
		ans = max(ans, sum);
		sum = 0; 
	}
	cout << ans;
	return 0;
}
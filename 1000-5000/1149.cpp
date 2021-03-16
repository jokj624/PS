//AC
//BOJ 1149 RGB 거리
//https://www.acmicpc.net/problem/1149
 
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int dp[1001][3];
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			cin >> dp[i][j];
		}
	}
	int total[1001][3]={0};
	total[0][0] = dp[0][0];
	total[0][1]	= dp[0][1];
	total[0][2] = dp[0][2];
	for(int i=1; i<n; i++){
		total[i][0] = dp[i][0] + min(total[i-1][1], total[i-1][2]);
		total[i][1] = dp[i][1] + min(total[i-1][0], total[i-1][2]);
		total[i][2] = dp[i][2] + min(total[i-1][0], total[i-1][1]);
	}
	int num = min(total[n-1][2],min(total[n-1][0],total[n-1][1]));
	cout << num << endl;
}

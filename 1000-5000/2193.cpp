//AC
//BOJ 2193 이친수
//https://www.acmicpc.net/problem/2193 
#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int dp[100][2]={0};
	dp[1][1] = 1;
	dp[1][0] = 0;
	for(int i=2; i<=n; i++){
	 	dp[i][0] = dp[i-1][1] + dp[i-1][0];
	 	dp[i][1] =	dp[i-1][0]; 
	}
	int total = dp[n][0] + dp[n][1];
	cout << total << endl;
}

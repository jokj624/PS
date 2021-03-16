//AC
//BOJ 1520 내리막 길
//https://www.acmicpc.net/problem/1520 
#include <iostream>
using namespace std;
int n,m;
int arr[501][501];
long long dp[501][501];
long long way(int i, int j){
	if(i == (n-1) && j ==(m-1)){
		return 1;
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	dp[i][j] = 0;
	if(arr[i+1][j] < arr[i][j] && i+1 < n){
		dp[i][j] += way(i+1,j);	
	}
	if(arr[i-1][j] < arr[i][j] && i-1 >= 0){
		dp[i][j] += way(i-1, j);		
	}
	if(arr[i][j+1]<arr[i][j] && j+1 < m){
		dp[i][j] += way(i,j+1);
	}
	if(arr[i][j-1] <arr[i][j] && j-1 >= 0){
		dp[i][j] += way(i,j-1);
	}
	return dp[i][j];
}
int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &arr[i][j]);
			dp[i][j] = -1;
		}
	}
	cout << way(0,0);
}

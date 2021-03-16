//AC
//BOJ 7579 앱
#include <iostream>
#include <vector>
using namespace std;
int dp[101][10001];
int memory[101];
int c[101];
int main(){
	int n, m, ans = 987654321;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		scanf("%d", &memory[i]);
	}
	for(int i=0; i<n; i++){
		scanf("%d", &c[i]);
	}
	dp[0][c[0]] = memory[0];
	for(int i=0; i<n; i++){
		for(int j=0; j<=10000; j++){
			if(j >= c[i]){
				if(i>0)	dp[i][j] = max(dp[i-1][j], dp[i-1][j-c[i]]+memory[i]);
			}
			if(i>0)	dp[i][j] = max(dp[i-1][j], dp[i][j]);
			
			if(dp[i][j] >= m){
				ans = min(j, ans);
			}
		}
	}
	cout << ans;
	return 0;
}

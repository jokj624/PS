//AC
//BOJ 12909 그래프 만들기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int score[52];
int dp[52][52];
int solve(int node, int edge){
	if(dp[node][edge] != -1)	return dp[node][edge];
	if(node <= 0)	return 0;
	for(int i=1; i<node; i++){
		dp[node][edge] = max(dp[node][edge], solve(i, 1) + solve(node-i, edge+1));
	}
	return dp[node][edge];
}
int main(){
	cin >> N;
	for(int i=0; i<=N; i++){
		for(int j=0; j<=N; j++){
			dp[i][j] = -1;
		}
	}
	for(int i=1; i<N; i++){
		scanf("%d", &score[i]);
		dp[1][i] = score[i];
	}

	int ans = solve(N, 0);
	cout << ans;
	return 0;
}

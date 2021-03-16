//AC
//BOJ 2293 동전 1
//https://www.acmicpc.net/problem/2293 
#include <iostream>
#define MAX 100001
using namespace std;
int value[101];
int dp[MAX];
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++){
		scanf("%d", &value[i]);
	}
	dp[0] = 1;
	for(int i=1; i<=n; i++){
		for(int j=value[i]; j<=k; j++){
			dp[j] += dp[j-value[i]];
		}
	}
	printf("%d", dp[k]);
	return 0;
} 

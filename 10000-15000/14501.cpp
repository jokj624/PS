//AC
//BOJ 14501 퇴사
// https://www.acmicpc.net/problem/14501 
#include <iostream>
#include <algorithm>
using namespace std;
int p[16];
int t[16];
int dp[16];
int main(){
	int n;
	int day;
	cin >> n;
	for(int i=1; i<=n; i++){
		scanf("%d %d", &day, &p[i]);
		t[i] = day+i;
	}
	int temp = 0;
	for(int i=1; i<=n; i++){
		if(t[i] <= n+1)	dp[i] = p[i];
		for(int j=1; j<i; j++){
			if(t[j] <= i){
				temp=max(dp[j], temp);	
			}
		}
		dp[i] += temp;
		temp=0;
	}
	int max1 = 0;
	for(int i=1; i<=n; i++){
		if(max1 < dp[i])	max1 = dp[i];
	}
	cout << max1;
}

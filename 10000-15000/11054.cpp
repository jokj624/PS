//AC
//BOJ 11054 가장 긴 바이토닉 부분 수열
//https://www.acmicpc.net/problem/11054
#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int dp1[1001];
int dp2[1001];
int main(){
	int n, ans=1;
	bool ch = false;
	cin >> n;
	for(int i=1; i<=n; i++){
		scanf("%d", &arr[i]);
		if(i>1 && arr[i]!=arr[i-1])	ch=true;
	}
	if(!ch){
		printf("1");
		return 0;
	}
	dp1[1] = 1;
	dp2[n] = 1;
	for(int i=2; i<=n; i++){
		dp1[i] = 1;
		for(int j=1; j<i; j++){
			if(arr[i]>arr[j]){
				dp1[i] = max(dp1[i], dp1[j]+1);
			}
		}
	}//정방향  
	for(int i=n-1; i>=1; i--){
		dp2[i] = 1;
		for(int j=n; j>i; j--){
			if(arr[i]>arr[j]){
				dp2[i] = max(dp2[i], dp2[j]+1);
			}
		}
	}//역방향  
	for(int i=1; i<=n; i++){
		ans = max(ans, dp1[i]+dp2[i]-1);
	}
	printf("%d", ans);
	return 0;
} 

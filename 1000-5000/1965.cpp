//AC
//BOJ 1965 상자넣기 
// https://www.acmicpc.net/problem/1965
#include <iostream>
using namespace std;
int main(){
	int n;
	int arr[1000];
	int dp[1000]={0};
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> arr[i];
		dp[i] = 1;
	}
	dp[1] = 1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			if(arr[i] > arr[j] && dp[j]+1 > dp[i]){
				dp[i] = dp[j] + 1;
			}
		}
	}
	int m = 0;
	for(int i=1; i<=n; i++){
		if(m < dp[i]){
			m = dp[i];
		}
	}
	cout << m;
}

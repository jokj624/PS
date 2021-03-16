//AC
//BOJ 17216 가장 큰 감소 부분 수열
//https://www.acmicpc.net/problem/17216 

#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int arr[1001];
int main(){
    int n;
    int ans = 0;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        dp[i] = arr[i];
    }
    for(int i=2; i<=n; i++){
        for(int j=1; j<i; j++){
            if(arr[j] > arr[i]){
                dp[i] = max(dp[i], dp[j]+arr[i]);    
            }
        }
    }
    for(int i=1; i<=n; i++){
        ans = max(dp[i], ans);
    }
    cout << ans;
    return 0;
}

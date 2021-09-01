//AC
//BOJ 17626 Four Squares
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
int dp[50001];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i=4; i<=N; i++) {
        int root = sqrt(i);
        dp[i] = i;
        if(root * root == i)  {
            dp[i] = 1;
            continue;
        }
        for(int j=1; j<=root; j++) {
            dp[i] = min(dp[i], dp[j*j]+dp[i-(j*j)]);
        }
    }
    cout << dp[N];
    return 0;
}
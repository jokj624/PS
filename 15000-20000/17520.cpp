#include <iostream>
using namespace std;
typedef long long ll;
#define SIZE 101010
#define MOD 16769023
ll dp[SIZE];
int main() {
    int n;
    scanf("%d", &n);
    dp[1] = 2;  dp[2] = 2;
    for(int i=3; i<=n; i++) {
        if(i % 2) {
            dp[i] = (dp[i-1] * 2) % MOD;
        }
        else    dp[i] = dp[i-1];
    }
    printf("%lld", dp[n]);
    return 0;
}
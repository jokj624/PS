//AC
//BOJ 1932 정수 삼각형
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int tri[501][501];
int dp[501][501];
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++)
        {
            scanf("%d", &tri[i][j]);
        }
    }
    if (n == 1) {
        cout << tri[0][0];
        return 0;
    }
    dp[0][0] = tri[0][0];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i + 1; j++) {
            dp[i][j] = tri[i][j];
            if (j == 0) {
                dp[i][j] += dp[i - 1][j];
                continue;
            }
            if (j == i) {
                dp[i][j] += dp[i - 1][j - 1];
                continue;
            }
            dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}
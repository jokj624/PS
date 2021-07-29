//AC
//BOJ 17845 수강과목
#include <iostream>
using namespace std;
int dp[1001][10001];
int w[1001];
int v[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, ans = 0;
    cin >> k >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i == 0) {
                if (j - w[0] >= 0)
                    dp[0][j] = v[0];
                continue;
            }
            if (j - w[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
        ans = max(ans, dp[i][k]);
    }
    cout << ans << "\n";
    return 0;
}
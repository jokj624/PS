//AC
//BOJ 13333 Q-인덱스
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, arr[1001];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", arr + i);
    sort(arr + 1, arr + n + 1);
    int q_index = 0;
    for (int k = 0; k <= 10'000; ++k) {
        int *i = upper_bound(arr + 1, arr + n + 1, k - 1); // 
        int idx = (i - arr); 
        if (n - idx + 1 >= k && arr[n - k] <= k) {
            q_index = k;
            break;
        }
    }
    printf("%d", q_index);
}

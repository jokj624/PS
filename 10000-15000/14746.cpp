//AC
//BOJ 14746 Closest Pair
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define INF 987654321
typedef long long ll;
vector<int> p;
vector<int> q;
int main() {
    int n, m, c1, c2, num;
    scanf("%d %d", &n, &m);
    scanf("%d %d", &c1, &c2);
    for(int i=0; i<n; i++) {
        scanf("%d", &num);
        p.push_back(num);
    }
    for(int i=0; i<m; i++) {
        scanf("%d", &num);
        q.push_back(num);
    }
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    int min_value = INF, cnt = 0, lower_value, upper_value;
    for(int i=0; i<n; i++){
        int value = p[i];
        int idx = upper_bound(q.begin(), q.end(), value) - q.begin();
        if(idx >= m) {
            idx -= 1;
        }
        upper_value = q[idx];
        if(m == 1) {
            if(abs(value - upper_value) < min_value) {
                cnt = 1;
                min_value = abs(value - upper_value);
            }
            else if(abs(value - upper_value) == min_value)     cnt += 1;
            continue;
        }
        if(idx == 0)    lower_value = q[idx+1];
        else    lower_value = q[idx - 1];
        int upsum_value = abs(value - upper_value);
        int losum_value = abs(value - lower_value);
        if(upsum_value == losum_value) {
           if(upsum_value == min_value) {
                cnt += 2;
            }
            else if (upsum_value < min_value) {
                min_value = upsum_value;
                cnt = 2;
            }
        }
        else {
            int min_sum_value = min(upsum_value, losum_value);
            if(min_sum_value == min_value) {
                cnt += 1;
            }
            else if(min_sum_value < min_value) {
                min_value = min_sum_value;
                cnt = 1;
            }
        }    
    }
    ll ans = abs(c1 - c2) + min_value;
    printf("%lld %d", ans, cnt);
}

//AC
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> arr;
vector<ll> row;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll add = 3;
    arr.resize(100000);
    row.resize(100000);
    arr[0] = 0; arr[1] = 1; arr[2] = 2;
    row[0] = 0; row[1] = 1;
    for(int i=3; i<=99999; i++) {
        arr[i] = arr[i-1] + add;
        add += 2;
    }
    add = 3;
    for(int i=2; i<=99999; i++) {
        row[i] = row[i-1] + add;
        add += 2;
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int idx = lower_bound(arr.begin(), arr.end(), n) - arr.begin();
        int r_idx = lower_bound(row.begin(), row.end(), n) - row.begin();
        if(idx >= 100000)    idx -= 1;
        if(idx == 0)    idx += 1;
        if(arr[idx] > n)    idx -= 1;
        if(r_idx >= 100000)   r_idx -= 1; 
        if(r_idx == 0)  r_idx += 1;
        int ansR = (n-arr[idx]+1 < r_idx) ? n-arr[idx]+1 : r_idx;
        int ansC = (row[r_idx] - n + 1 < idx) ? row[r_idx] - n + 1 : idx;
        cout << ansR << " " << ansC << "\n";
    }

    return 0;
}
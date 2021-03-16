//AC 
//BOJ 2878 캔디캔디
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> candy;
int main(){
    int M, N;
    vector<unsigned long long> candy;
    unsigned long long avg = 0, sum = 0;
    unsigned long long ans = 0;
    cin >> M >> N;
    for(int i=0; i<N; i++){
        unsigned long long a;
        scanf("%lld", &a);
        sum += a;
        candy.push_back(a);
    }
    sum = (sum - M);
    sort(candy.begin(), candy.end());
    for(int i=0; i<N; i++){
        candy[i] = min(candy[i], sum/(N-i));
        sum -= candy[i];
        ans += candy[i]*candy[i];
    }
    cout << ans;
    return 0;
}


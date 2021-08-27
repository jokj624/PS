//AC
//BOJ 11279 최대힙
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
priority_queue<int> pq;
int solve() {
    if(pq.empty())  return 0;
    int n = pq.top();
    pq.pop();
    return n;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; 
    cin >> N;
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        if(!x) {
            cout << solve() << "\n";
        }
        else    pq.push(x);
    }
    return 0;
}
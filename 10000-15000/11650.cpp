//AC
//BOJ 11650 좌표 정렬하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;
bool cmp(const pii &a, const pii &b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), cmp);
    for(auto point : v) {
        cout << point.first << " " << point.second << "\n";
    }
    return 0;
}
//AC
//BOJ 13904 과제
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
vector<pair<int, int>> v;
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second > b.second;
}
int day[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int d, w;
        cin >> d >> w;
        v.push_back({d, w});
    }
    sort(v.begin(), v.end(), cmp);
    int maxW = 0;
    for(int i=0; i<N; i++) {
        int curD = v[i].first;
        int curW = v[i].second;
        for(int j = curD; j >= 1; j--) {
            if(!day[j]) {
                day[j] = 1;
                maxW += curW;
                break;
            }
        }
        
    }
    cout << maxW;
    return 0;
}
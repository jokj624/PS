//AC
//BOJ 2751 수 정렬하기 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    for(int a: v) {
        cout << a << '\n';
    }
    return 0;
}
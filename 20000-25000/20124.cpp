//AC
//BOJ 20124 모르고리즘 회장님 추천받습니다
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
map<string, int> score;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    string name;
    int s;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> name >> s;
        score[name] = s;
    }
    int ans = 0;
    string ans_name;
    for(auto tmp : score) {
        if (tmp.second > ans) {
            ans = tmp.second;
            ans_name = tmp.first;
        }
    }
    cout << ans_name;
    return 0;
}
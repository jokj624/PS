//AC
//BOJ 23056 참가자 명단
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, string> pis;
vector<pis> odd;
vector<pis> even;
int possible[11];
bool cmp (const pis &a, const pis &b) {
    if(a.first == b.first) {
        if(a.second.size() == b.second.size()) {
            return a.second < b.second;
        }
        else    return a.second.size() < b.second.size();
    }
    return a.first < b.first;
}
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++) {
        possible[i] = M;
    }
    while(1) {
        int num;
        string name;
        cin >> num >> name;
        if(num == 0)    break;
        if(num % 2) {
            if(possible[num] > 0) {
                odd.push_back({num, name});
                possible[num]--;
            }
        }
        else {
            if(possible[num] > 0) {
                even.push_back({num, name});
                possible[num]--;
            }
        }
    }
    sort(odd.begin(), odd.end(), cmp);
    sort(even.begin(), even.end(), cmp);
    for(auto tmp: odd) {
        cout << tmp.first << " "<<tmp.second << "\n";
    }
    for(auto tmp: even) {
        cout << tmp.first << " " << tmp.second << "\n";
    }
    return 0;
}
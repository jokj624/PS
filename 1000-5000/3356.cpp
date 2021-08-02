//AC
//BOJ 3356 라디오 전송
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
#define INF 2e9+1
typedef long long ll;
vector<ll> makeTable(string pattern) {
    int j = 0;
    vector<ll> table(pattern.size(), 0);
    for (int i = 1; i < pattern.size(); i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }
    return table;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    int N;
    cin >> N;
    cin >> str;
    vector<ll> fail = makeTable(str);
    cout << (N - fail[N-1]);
    return 0;
}
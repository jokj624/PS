//AC
//BOJ 1787 문자열의 주기예측
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
#define endl '\n'
#define SIZE 1010101
typedef long long ll;
int ans[SIZE];
vector<int> makeTable(string pattern) {
    int j = 0;
    vector<int> table(pattern.size(), 0);
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
    int N;
    ll cnt = 0;
    string str;
    cin >> N;
    cin >> str;
    vector<int> fail = makeTable(str);
    for(int i = 0; i < N; i++) {
        if(fail[i]) {
            if(fail[fail[i]-1]) {
                ans[i] = ans[fail[i]-1];
            }
            else    ans[i] = fail[i];
            if(ans[i])  cnt += ((i+1) - ans[i]);
        }
    }
    cout << cnt;
    return 0;
}
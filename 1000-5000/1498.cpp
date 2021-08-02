//AC
//BOJ 1498 주기문
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
#define endl '\n'
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
    string str;
    cin >> str;
    vector<int> fail = makeTable(str);
    for(int i=0; i<str.size(); i++) {
        if(fail[i]) {
            if((i+1) % (i+1 - fail[i]) == 0) {
                cout << i + 1 << " " << (i+1)/(i+1 - fail[i]) << endl;
            }
        }
    }

    return 0;
}
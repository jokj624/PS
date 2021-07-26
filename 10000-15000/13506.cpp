//AC
//BOJ 13506 카멜레온 부분 문자열
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int cnt = 0;
vector<int> failFunc(string pattern) {
    int j =0;
    vector<int> table(pattern.size(), 0);
    for(int i=1; i<pattern.size(); i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = table[j-1];
        }
        if (pattern[i] == pattern[j]) {
            table[i] = ++j; 
        }
    }
    return table;
}
void KMP(string parent, string pattern, vector<int> table)
{
    int j = 0;
    for (int i = 0; i < parent.size(); i++) {
        while (j > 0 && parent[i] != pattern[j]) {
            j = table[j - 1];
        }
        if (parent[i] == pattern[j]) {
            if (j == pattern.size() - 1) {
                cnt++;
                j = table[j];
            }
            else     j++;
        }
    }
    return;
}
int main() {
    string str;
    cin >> str;
    vector<int> table = failFunc(str);
    if(!table[str.size()-1]) {   
        printf("-1");
        return 0;
    }
    for(int i = table[str.size()-1]; i; i = table[i-1]) {
        string temp = str.substr(0, i);
        KMP(str, temp, table);
        if(cnt > 2) {
            cout << temp;
            return 0;
        }
        cnt = 0;
    }
    printf("-1");
    return 0;
}
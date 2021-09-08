//AC
//BOJ 1181 단어 정렬
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
vector<string> v;
map<string, int> m;
bool cmp(const string &a, const string &b) {
    if(a.size() == b.size())    return a < b;
    return a.size() < b.size();
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    v.resize(N);
    for(int i=0; i<N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), cmp);
    for(auto a : v) {
        if(!m[a])   cout << a << "\n";
        m[a] = 1;
    }
    return 0;
}
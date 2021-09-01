//AC
//BOJ 17219 비밀번호 찾기
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
map<string, string> m;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, M;
    string site, pw;
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> site >> pw;
        m[site] = pw;
    }
    for(int i=0; i<M; i++) {
        cin >> site;
        cout << m[site] << "\n";
    }
    return 0;
}
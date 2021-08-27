//AC
//BOJ 10814 나이순 정렬
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
vector<string> m[201];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, age;
    string name;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> age >> name;
        m[age].push_back(name);
    }
    for(int i=1; i<=200; i++) {
        if(!m[i].empty()) {
            for(string n : m[i]) {
                cout << i << " " << n << "\n";
            }
        }
    }
    return 0;
}
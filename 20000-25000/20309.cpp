//AC
//BOJ 20309 트리플 소트
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, num, ck = 0;
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> num;
        if(i%2) {
            if(num % 2 == 0)    ck = 1; 
        }
        else {
            if(num % 2)     ck = 1;
        }
    }
    if(ck)  cout << "NO";
    else    cout << "YES";
    return 0;
}
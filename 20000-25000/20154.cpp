//AC
//BOJ 20154 이 구역의 승자는 누구야?
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int arr[] = {3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1};
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    int ans = 0;
    cin >> s;
    for(int i=0; i<s.size(); i++) {
        ans += (arr[s[i]-'A']);
        ans %= 10;
    }
    if(ans % 2) cout << "I'm a winner!";
    else    cout << "You're the winner?";
    return 0;
}
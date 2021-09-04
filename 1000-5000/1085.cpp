//AC
//BOJ 1085 직사각형에서 탈출
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    cout << min({x, y, w-x, h-y});
    return 0;
}
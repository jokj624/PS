//AC
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int arr[1001];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int num = 1;
    for(int i=1; i<=1000; i++) {
        while(!(num % 3) || (num % 10 == 3))  num++;
        arr[i] = num;
        num++;
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << arr[n] << "\n";
    }
    return 0;
}
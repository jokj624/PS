//AC
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int mod3 = n / 3;
        if (n == mod3 * 2 + mod3 + 1) {
            cout << mod3 + 1 << " " << mod3<< "\n";
        }
        else if (n == mod3 + (mod3 + 1) * 2) {
            cout << mod3 << " " << mod3 + 1 << "\n";
        }
        else    cout << mod3 << " " << mod3 << "\n";
    }

    return 0;
}
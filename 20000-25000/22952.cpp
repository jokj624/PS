//AC
//BOJ 22952 Permutation Making
#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    int f = 1;
    int b = N;
    for(int i=1; i<=N; i++) {
        if(i%2) cout << b-- << " ";
        else    cout << f++ << " ";
    }
    return 0;
}
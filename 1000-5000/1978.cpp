//AC
//BOJ 1978 소수 찾기
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int is_prime(int x) {
    if(x == 1)  return 0;
    if(x == 2)  return 1;
    int prime = 1;
    for(int i=2; i<=sqrt(x); i++) {
        if(!(x%i)) {
            prime = 0;
            break;
        }
    }
    if(prime)   return 1;
    else    return 0;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, cnt = 0;
    cin >> N;
    for(int i=0; i<N; i++) {
        int n;
        cin >> n;
        if(is_prime(n)) cnt++;
    }
    cout << cnt;
    return 0;
}
//AC
//BOJ 1929 소수 구하기
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
int is_prime(int x) {
    if (x == 1)    return 0;
    if (x == 2)    return 1;
    int prime = 1;
    for (int i = 2; i <= sqrt(x); i++) {
        if (!(x % i)) {
            prime = 0;
            break;
        }
    }
    if (prime)    return 1;
    else    return 0;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i=N; i<=M; i++) {
        if(is_prime(i)) cout << i << "\n";
    }
    return 0;
}

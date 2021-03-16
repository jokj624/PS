//AC
//BOJ 16283 Farm

#include <iostream>
using namespace std;
int main(){
    int a, b, n, w, cnt = 0;
    int goat, sheep;
    cin >> a >> b >> n >> w;
    for(int i=1; i<n; i++){
        if(a*i + b*(n-i) == w){
            cnt++;
            sheep = i;
            goat = (n-i);
        }
    }
    if(cnt == 1)    printf("%d %d", sheep, goat);
    else    printf("-1");
    return 0;
}
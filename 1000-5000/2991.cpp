//AC
//BOJ 2991 사나운 개
#include <iostream>
using namespace std;
int main(){
    int a, b, c, d;
    int P, M, N;
    cin >> a >> b >> c >> d;
    cin >> P >> M >> N;
    int p = P %(a+b);
    int m = M % (a+b);
    int n = N % (a+b);
    int p2 = P % (c+d);
    int m2 = M % (c+d);
    int n2 = N % (c+d);
    for(int i=0; i<3; i++){
        int cnt = 0;
        if(i==0){
            if(P <= (a+b))   p = P;
            if(P <= (c+d))   p2 = P;
            if(p <= a)  cnt+=1;
            if(p2 <= c)     cnt+=1;
        }
        else if(i==1){
            if(M <= (a+b))   m = M;
            if(M <= (c+d))   m2 = M;
            if(m <= a)   cnt+=1;
            if(m2 <= c)  cnt+=1;
        }
        else if(i==2) {
            if(N <= (a+b))   n = N;
            if(N <= (c+d))   n2 = N;
            if(n <= a)   cnt+=1;
            if(n2 <= c)  cnt+=1;
        }
        cout << cnt << "\n";
    }
    return 0;
}
//AC
//BOJ 10775 공항

#include <iostream>
#define MAX 101010
using namespace std;
int gate[MAX];
int Find(int x){
    if(gate[x] == x)    return x;
    gate[x] = Find(gate[x]);
    return gate[x];
}
void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    gate[y] = x;
}
int main(){
   int G, P, g, ans=0;
   bool check = false;
   cin >> G >> P;
   for(int i=0; i<=G; i++){
       gate[i] = i;
   }
   for(int i=1; i<=P; i++){
       scanf("%d", &g);
       if(check)    continue;
       int rGate = Find(g);
       if(rGate != 0){
           ans += 1;
           Union(rGate-1, rGate);
       }
       else
       {
           check = true;
       }
       
   }
   cout << ans << "\n";
   return 0;
} 

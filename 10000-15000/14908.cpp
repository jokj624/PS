//AC
//BOJ 14908 구두 수선공
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const pair<int, double> &a, const pair<int, double> &b){
   if(a.second != b.second){
       return a.second > b.second;
   }
   else{
       return a.first < b.first;
   }
}
int main(){
    int N;
    cin >> N;
    vector<pair<int,double> > weight;
    for(int i=0; i<N; i++){
        double t, s;
        scanf("%lf %lf", &t, &s);
        weight.push_back({i+1, s/t});
    }
    sort(weight.begin(),weight.end(), cmp);
    for(int i=0; i<N; i++){
        printf("%d ", weight[i].first);
    }
    return 0;
} 

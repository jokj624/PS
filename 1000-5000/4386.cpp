//AC
//BOJ 4386 별자리 만들기 
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct Star{
    int start, end;
    double dist;
};
vector<pair<double, double> > v;
vector<Star> star;
int parent[101];
bool cmp(const Star &s1, const Star &s2){
    return s1.dist < s2.dist;
}
int Find(int x){
    if(x==parent[x])    return x;
    parent[x] = Find(parent[x]);
    return parent[x];
}
void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x < y)   parent[y] = x;
    else    parent[x] = y;
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        double a, b;
        cin >> a >> b;
        v.push_back({a,b});
        parent[i+1] = i+1;
    }
    double ans = 0.0f, x1, x2, y1, y2;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            x1 = v[i].first;
            y1 = v[i].second;
            x2 = v[j].first;
            y2 = v[j].second;
            double dis = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
            star.push_back({i+1, j+1, dis});
            star.push_back({j+1, i+1, dis});
        }
    }
    sort(star.begin(), star.end(), cmp);
    for(Star tmp : star){
        if(Find(tmp.start) != Find(tmp.end)){
            ans += tmp.dist;
            Union(Find(tmp.start), Find(tmp.end));
        }
    }
    printf("%.2lf", ans);
    return 0;
}
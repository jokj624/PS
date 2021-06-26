//AC
//BOJ 1854 K번째 최단경로 찾기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
struct Edge{
    int to; int cost;
};

vector<Edge> v[1001];
priority_queue<int> d[1001]; 
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int >> > pq;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=0; i<m; i++){
        int s, e, c;
        scanf("%d %d %d", &s, &e, &c);
        v[s].push_back({e, c});
    }
  
    d[1].push(0); 
    pq.push({0, 1});
    while(!pq.empty()){
        int cost = pq.top().first;
        int city = pq.top().second;
        pq.pop();
        
        for(int i=0; i<v[city].size(); i++){
            int next = v[city][i].to;
            if(d[next].size() < k){
                d[next].push(cost + v[city][i].cost);
                pq.push({ cost+v[city][i].cost, next });
            }  
            else if(d[next].top() > cost + v[city][i].cost){
                d[next].pop();
                d[next].push(cost + v[city][i].cost);
                pq.push({ cost + v[city][i].cost, next});
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(d[i].size() == k)    printf("%d\n", d[i].top());
        else    printf("-1\n");
    }
    return 0;
}
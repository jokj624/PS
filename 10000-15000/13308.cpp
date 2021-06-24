//AC
//BOJ 13308 주유소
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define SIZE 2501
#define INF 1e9+1
using namespace std;
typedef pair<int, int> edge;
int L[SIZE];
vector<edge> graph[SIZE];
struct city{
    int node; int prev; long long cost;
};
struct cmp{
    bool operator()(const city &a , const city &b){
        return a.cost > b.cost;
    }
};
priority_queue<city, vector<city>, cmp > pq;
int visit[SIZE][SIZE];
int main(){
    int N, M;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        scanf("%d", &L[i]);
    }
    for(int i=0; i<M; i++){
        int s, e, c;
        scanf("%d %d %d", &s, &e, &c);
        graph[s].push_back({e, c});
        graph[e].push_back({s, c});
    }
    pq.push({1, L[1], 0});
    long long dist=0, ans = 0;
    while(!pq.empty()){
        int node = pq.top().node;
        int prev = pq.top().prev;
        long long cost = pq.top().cost;
        pq.pop();
        if(node == N){
            ans = cost;
            break;
        }
        if(visit[node][prev])   continue;
        visit[node][prev] = true;
        for(int i=0; i<graph[node].size(); i++){
            int next = graph[node][i].first;
            dist = cost + graph[node][i].second * prev;
            pq.push({next, min(prev, L[next]), dist});
        }
    }
 
    cout << ans;
}

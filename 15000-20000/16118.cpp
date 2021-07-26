//AC
//BOJ 16118 달빛 여우 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 2e9+1
typedef long long ll;
typedef pair<ll, ll> edge;
vector<edge> graph[4001];
int main() {
    int n, m;
    cin >> n >> m;
    ll d[n + 1];
    ll wolf[n + 1][2];
    bool c[n + 1];
    for (int i = 0; i < m; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost*2});
        graph[to].push_back({from, cost*2});
    }
    for (int i = 1; i <= n; i++){
        d[i] = INF;
        wolf[i][0] = INF;    wolf[i][1] = INF;
        c[i] = false;
    }
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push({0, 1});
    d[1]=0;
    while (!pq.empty()) {  // 여우
        ll x = pq.top().second;
        pq.pop();
        if (!c[x]){
            c[x] = true;
            for (int j = 0; j < graph[x].size(); j++){
                int y = graph[x][j].first;
                if (d[y] > d[x] + graph[x][j].second) {
                    d[y] = d[x] + graph[x][j].second;
                    pq.push({d[y], y});
                }
            }
        }
    }
    priority_queue<pair<ll, pair<ll, ll>>> pq2;
    pq2.push({0, {1, 0}});  // 늑대 
    wolf[1][0] = 0;
    while (!pq2.empty()) {
        ll cc = -pq2.top().first;
        ll x = pq2.top().second.first;
        ll z = pq2.top().second.second;
        pq2.pop();
        if(wolf[x][z] < cc) continue;
        for (int j = 0; j < graph[x].size(); j++) {
            int y = graph[x][j].first;
            ll nextCost = 0;
            if(z)   nextCost = graph[x][j].second * 2;
            else    nextCost = graph[x][j].second / 2;
            if (wolf[y][!z] > cc + nextCost) {
                wolf[y][!z] = cc + nextCost;
                pq2.push({-wolf[y][!z], {y, !z}});
            }
        }
    }
    ll ans = 0;
    for(int i=1; i<=n; i++){
        if(d[i] < min(wolf[i][0], wolf[i][1]) && d[i] != INF){
            ans += 1;
        }
    }
    printf("%lld", ans);
    return 0;
}
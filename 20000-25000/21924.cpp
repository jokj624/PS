//AC
//BOJ 21924 도시 건설
#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 101010
using namespace std;
typedef long long ll;
int parent[SIZE];
bool visit[SIZE];
vector<int> graph[SIZE];
struct Edge{
    int from, to, cost;
    bool operator < (const Edge& other) const{
        return cost < other.cost;
    }
};
int Find(int x){
    if(parent[x] == x)  return x;
    return parent[x] = Find(parent[x]);
}
void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(y < x)   parent[y] = parent[x];
    else    parent[x] = parent[y];
}
void dfs(int x){
    visit[x] = true;
    for(int i=0; i<graph[x].size(); i++){
        if(!visit[graph[x][i]]){
            dfs(graph[x][i]);
        }
    }
}
int main(){
    int N, M;
    int from, to, cost;
    ll costSum = 0, mstSum=0;
    cin >> N >> M;
    vector<Edge> node(M);
    for(int i=0; i<M; i++){
        cin >> node[i].from >> node[i].to >> node[i].cost;
        costSum += node[i].cost;
        graph[node[i].from].push_back(node[i].to);
        graph[node[i].to].push_back(node[i].from);
    }
    
    dfs(1);
    for(int i=1; i<=N; i++){
        parent[i] = i;
        if(!visit[i]){
            printf("-1");
            return 0;
        }
    }
    sort(node.begin(), node.end());
    for(int i=0; i<M; i++){
        if(Find(node[i].from) != Find(node[i].to)){
            mstSum += node[i].cost;
            Union(Find(node[i].from), Find(node[i].to));
        }
    }
    ll ans = costSum - mstSum;
    printf("%lld", ans);
    return 0;
}
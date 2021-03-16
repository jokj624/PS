//BOJ 1005 ACM Craft
//Ac
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
vector<int> graph[1010];
int cost[1010];
int ind[1010];
int count_time(int N, int end){
    queue<int> q;
    int d[N+1];
    int ans = 0;
    for(int i=1; i<=N; i++){
        if(ind[i] == 0){
            q.push(i);
            d[i] = cost[i];
        }
        else    d[i] = 0;
    }
    for(int i=1; i<=N; i++){
        int x = q.front();
        q.pop();
        for(int j : graph[x]){
            ind[j]--;
            d[j] = max(d[j], d[x]+cost[j]);
            if(ind[j] == 0){
                q.push(j);
            }
        }
    }
    return d[end];
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int N, K, end;
        memset(graph, 0, sizeof(graph));
        scanf("%d %d", &N, &K);
        for(int i=1; i<=N; i++){
            scanf("%d", &cost[i]);
            ind[i] = 0;
        }
        for(int i=0; i<K; i++){
            int s, e;
            scanf("%d %d", &s, &e);
            ind[e]++;
            graph[s].push_back(e);
        }
        scanf("%d", &end);
        printf("%d\n", count_time(N, end));
    }
    return 0;
}
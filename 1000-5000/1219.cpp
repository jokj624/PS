//AC
//BOJ 1219 오민식의 고민
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 9876543210;
typedef long long ll;
vector<pair<int, int> > graph[101];
int money[101];
int c[101];
int cnt[101];
ll d[101];
int ck[101];
int N, s, e, M;
int dfs(int x){
    queue<int> next;
    int visit[N];
    fill(visit, visit+N, 0);
    next.push(x);
    while(!next.empty()){
        int nx = next.front();
        next.pop();
        if(nx == e)  return 1;
        visit[nx] = 1;
        for(auto t : graph[nx]){
            if(!visit[t.first]){
                next.push(t.first);
            }
        }
    }
    return 0;
}
int main(){
    
    cin >> N >> s >> e >> M;
    for(int i=0; i<M; i++){
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        graph[from].push_back({to, cost});
    }
    for(int i=0; i<N; i++){
        scanf("%d", &money[i]);
        d[i] = INF;
    }
    
    queue<int> q;
    bool negative_cycle = false;
    q.push(s);
    d[s] = 0 - money[s];   cnt[s]++;   c[s] = 1;

    while(!q.empty()){
        int start = q.front();
        q.pop();
        c[start] = 0;
        if(negative_cycle) {
            break;
        }
        for(auto &next  : graph[start]){
            int end = next.first;
            int cost = next.second;
            if(ck[end]) continue;
            if(d[end] > d[start] + cost - money[end]){
                d[end] = d[start] + cost - money[end];
                if(!c[end]){
                    q.push(end);
                    c[end] = 1;
                    cnt[end]++;
                    if(cnt[end] >= N && !ck[end]) {
                        if(dfs(end)){
                            negative_cycle = true;
                            break;
                        } 
                        else {
                            ck[end] = 1;
                            ck[start] = 1;
                        }
                    }
                }
            }
        }
    }
    if(!negative_cycle) {
        if(d[e] != 9876543210) {
            printf("%lld", -d[e]);
        }
        else {
            printf("gg");
        }
    }
    else{
        printf("Gee");
    }
    return 0;
}
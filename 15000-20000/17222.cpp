//AC
//BOJ 17222 위스키 거래
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
#define INF 987654321
#define SIZE 220
vector<int> v[SIZE];
int c[SIZE][SIZE];
int f[SIZE][SIZE];
int maxFlow(int s, int e) {
    int total = 0;
    while(1) {
        queue<int> q;
        vector<int> parent(SIZE, -1);
        q.push(s);
        while(!q.empty() && parent[s] == -1) {
            int cur = q.front(); 
            q.pop();
            for(int next : v[cur]) {
                if(c[cur][next] - f[cur][next] > 0 && parent[next] == -1) {
                    q.push(next);
                    parent[next] = cur;
                }
            }
        }
        if(parent[e] == -1) break;
        int amount = INF;
        for (int i = e; i != s; i = parent[i]) {
            amount = min(amount, c[parent[i]][i]-f[parent[i]][i]);
        }
        for (int i = e; i != s; i = parent[i]) {
            f[parent[i]][i] += amount;
            f[i][parent[i]] += amount;
        }
        total += amount;
    }
    return total;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    int cnt[N+M];
    int s = 0, e = N + M + 1;
    for (int i = 1; i <= N; i++) {
        cin >> cnt[i];
        v[e].push_back(i);
        v[i].push_back(e);
        c[i][e] = INF;
    }
    for (int i=N+1; i<=N+M; i++) {
        cin >> c[s][i];
        v[i].push_back(s);
        v[s].push_back(i);
        cnt[i] = c[s][i];
    }
    for(int i = N+1; i<=N+M; i++) {
        int n;
        cin >> n;
        for(int j=0; j<n; j++) {
            int node;
            cin >> node;
            v[i].push_back(node);
            v[node].push_back(i);
            c[i][node] = cnt[node];
        }
    }
    int total = maxFlow(s, e);
    cout << total;
    return 0;
}
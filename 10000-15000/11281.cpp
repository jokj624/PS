//AC
//BOJ 11281 2-SAT 4
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
vector<vector<int>> graph;
vector<vector<int>> re_graph;
vector<int> scc;
stack<int> s;
bool visit[20005];
void dfs(int x) {
    visit[x] = true;
    for (int next : graph[x]) {
        if (!visit[next]) {
            dfs(next);
        }
    }
    s.push(x);
}
void re_dfs(int x, int y) {
    visit[x] = true;
    scc[x] = y;
    for (int next : re_graph[x]) {
        if (!visit[next]) {
            re_dfs(next, y);
        }
    }
}
int re(int x, int N) {
    return x > N ? x - N : x + N;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    graph.resize(2 * N + 5);
    re_graph.resize(2 * N + 5);
    scc.resize(2 * N + 5);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        if (u < 0)    u = -u + N;
        if (v < 0)    v = -v + N;
        graph[re(u, N)].push_back(v);
        graph[re(v, N)].push_back(u);
        re_graph[u].push_back(re(v, N));
        re_graph[v].push_back(re(u, N));
    }

    for (int i = 1; i <= 2 * N; i++){
        if (!visit[i])    dfs(i);
    }
    memset(visit, false, sizeof(visit));
    int idx = 1;
    while (!s.empty()) {
        int x = s.top();
        s.pop();
        if (!visit[x]) {
            re_dfs(x, idx++);
        }
    }
    for (int i = 1; i <= N; i++) {
        if (scc[i] == scc[i + N]) {
            cout << 0 << '\n';
            return 0;
        }
    }
    cout << 1 << '\n';
    for (int i = 1; i <= N; i++) {
        cout << (scc[i] > scc[i + N]) << ' ';
    }
    return 0;
}
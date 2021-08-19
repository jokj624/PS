//AC
//BOJ 16915 호텔 관리
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define SIZE 100001
using namespace std;
vector<int> state[2 * SIZE];
vector<int> graph[2 * SIZE];
vector<vector<int>> sccGroup;
vector<int> scc;
int cur, top;
int room[SIZE];
int id[2 * SIZE];
int stack[2 * SIZE];
int dfs(int x) {
    id[x] = ++cur;
    stack[top++] = x;
    int link = id[x];
    for (auto next : graph[x]) {
        if (!id[next]) {
            link = min(link, dfs(next));
        }
        else if (!scc[next]) {
            link = min(link, id[next]);
        }
    }
    if (link == id[x]) {
        sccGroup.push_back(vector<int>());
        while (1) {
            int now = stack[top - 1];
            top--;
            scc[now] = sccGroup.size();
            sccGroup[scc[now] - 1].push_back(now);

            if (now == x)    break;
        }
    }
    return link;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    scc.resize(4 * SIZE);
    for (int i = 1; i <= N; i++) {
        cin >> room[i];
    }
    for (int i = 1; i <= M; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int n;
            cin >> n;
            state[n].push_back(i);
        }
    }
    for (int i = 1; i <= N; i++) {
        int one = state[i][0];
        int two = state[i][1];
        int not1 = one + M;
        int not2 = two + M;

        if (room[i]) {
            graph[one].push_back(two);
            graph[two].push_back(one);
            graph[not1].push_back(not2);
            graph[not2].push_back(not1);
        }
        else {
            graph[one].push_back(not2);
            graph[two].push_back(not1);
            graph[not1].push_back(two);
            graph[not2].push_back(one);
        }
    }
    for (int i = 1; i <= 2 * M; i++) {
        if (id[i] == 0)     dfs(i);
    }
    for (int i = 1; i <= M; i++) {
        if (scc[i] == scc[i + M]) {
            cout << 0 << '\n';
            return 0;
        }
    }
    cout << 1 << '\n';
    return 0;
}
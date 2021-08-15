//AC
//BOJ 4196 도미노
#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> v[100002];
stack<int> s;
bool visit[100002];
int vertex, e;
void dfs(int start) {
    visit[start] = true;
    for (int x : v[start]) {
        if (!visit[x]) {
            dfs(x);
        }
    }
    s.push(start);
}
void re_dfs(int start) {
    visit[start] = true;
    for (int x : v[start]) {
        if (!visit[x]) {
            re_dfs(x);
        }
    }
}
void init() {
    memset(visit, false, sizeof(visit));
    memset(v, 0, sizeof(v));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int cnt = 0;
        init();
        cin >> vertex >> e;
        for (int i = 0; i < e; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
        }
        for (int i = 1; i <= vertex; i++) {
            if (!visit[i]) {
                dfs(i);
            }
        }
        memset(visit, false, sizeof(visit));
        while (!s.empty()) {
            int x = s.top();
            s.pop();
            if (!visit[x]) {
                re_dfs(x);
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}
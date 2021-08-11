//AC
//BOJ 1960 행렬만들기
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
#define SIZE 1010
typedef pair<int, int> pii;
int capacity[SIZE][SIZE];
int flow[SIZE][SIZE];
vector<int> v[SIZE];
int maxFlow(int s, int e) {
    int total = 0;
    while(true) {
        queue<int> q;
        vector<int> parent(SIZE, -1);
        q.push(s);
        while(!q.empty() && parent[e] == -1) {
            int cur = q.front(); 
            q.pop();
            for(int next : v[cur]) {
                if(capacity[cur][next] - flow[cur][next] > 0 && parent[next] == -1) {
                    q.push(next);
                    parent[next] = cur;
                }
            }
        }
        if(parent[e] == -1) break;
        
        for(int i = e; i!=s; i = parent[i]) {
            flow[parent[i]][i] += 1;
            flow[i][parent[i]] -= 1;
        }
        total += 1;
    }
    return total;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    int s = 0, e = 2*N+1;
    int left = 0, right = 0;
    for(int i=1; i<=N; i++) {
        cin >> capacity[s][i];
        v[s].push_back(i);
        v[i].push_back(s);
        left += capacity[s][i];
    }
    for(int i=N+1; i<=2*N; i++) {
        cin >> capacity[i][e];
        v[i].push_back(e);
        v[e].push_back(e);
        right += capacity[i][e];
    }
    if (left != right) {
        cout << -1;
        return 0;
    }
    for(int i=1; i<=N; i++) {
        for(int j=N+1; j<=2*N; j++) {
            v[i].push_back(j);
            v[j].push_back(i);
            capacity[i][j] = 1;
        }
    }
    int total = maxFlow(s, e);
    if(total != left) {
        cout << -1;
        return 0;
    }
    cout << 1 << "\n";
    for(int i=1; i<=N; i++) {
        for(int j=N+1; j<=2*N; j++) {
            cout << flow[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
//AC
//BOJ 20666 인물이와 정수
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
priority_queue<pii, vector<pii>, greater<pii>> q;
ll add[101010];
int visit[101010];
vector<pii> item[101010];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    ll maxC = 0;
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        cin >> add[i];
    }
    int p;
    cin >> p;
    for(int i=0; i<p; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add[b] += c;
        item[a].push_back({b, c});
    }
    for(int i=1; i<=N; i++) {
        q.push({add[i], i});
    }
    int cnt = 0;
    while(cnt < M) {
        pii monster = q.top();
        q.pop();
        if(visit[monster.second])   continue;
        visit[monster.second] = 1;
        for (pii temp : item[monster.second]) {
            if(visit[temp.first])   continue;
            add[temp.first] -= temp.second;
            q.push({add[temp.first], temp.first});
        }
        if(maxC < monster.first)   maxC = monster.first;
        cnt += 1;
    }
    cout << maxC;
    return 0;
}
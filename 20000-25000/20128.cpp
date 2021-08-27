//AC
//BOJ 20218 Parity Constraint Shortest Path
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;
#define INF 9223372036854775807
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<pll, int> ppli;
priority_queue<ppli, vector<ppli>, greater<ppli>> pq;
vector<pll> v[101010];
ll odd[101010];
ll even[101010];
bool ck[101010];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, M, x, y, c;
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        cin >> x >> y >> c;
        v[x].push_back({y, c});
        v[y].push_back({x, c});
    }
    for(int i=1; i<=N; i++) {
        odd[i] = INF;
        even[i] = INF;
    }
    even[1] = 0;  // 1->1 짝수 최소는 무조건 0
    pq.push({{odd[1], even[1]}, 1});
    while(!pq.empty()) {
        int xx = pq.top().second;
        pq.pop();
        if(!ck[xx]) {
            //ck[xx] = true;
            for(auto tmp : v[xx]) {
                ll yy = tmp.first;
                if(tmp.second % 2) {
                    int check = 0;
                    if(odd[yy] > even[xx] + tmp.second && even[xx] != INF) { // 짝수 + 홀수 = 홀수
                        odd[yy] = even[xx] + tmp.second;
                        check = 1;
                    }
                    if(even[yy] > odd[xx] + tmp.second && odd[xx] != INF) { // 홀수 + 홀수 = 짝수
                        even[yy] = odd[xx] + tmp.second;
                        check = 1;
                    }
                    if(check) pq.push({{odd[yy],even[yy]}, yy});
                }
                else {
                    int check = 0;
                    if(even[yy] > even[xx] + tmp.second && even[xx] != INF) {  // 짝수 + 짝수 = 짝수
                        even[yy] = even[xx] + tmp.second;
                        check = 1;
                    }
                    if(odd[yy] > odd[xx] + tmp.second && odd[xx] != INF) {  // 짝수 + 홀수 = 홀수
                        odd[yy] = odd[xx] + tmp.second;
                        check = 1;
                    }
                    if(check) pq.push({{odd[yy], even[yy]}, yy});
                }
            }
        }
    }
    for(int i=1; i<=N; i++) {
        if(odd[i] != INF)   cout << odd[i] << " ";
        else    cout << -1 << " ";
        if(even[i] != INF)  cout << even[i] << " ";
        else    cout << -1 << " ";
        cout << "\n";
    }
    return 0;
}
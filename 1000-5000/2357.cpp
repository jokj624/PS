//AC
//BOJ 2357 최솟값과 최댓값
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
#define SIZE 100001
#define INF 1e9+7
typedef long long ll;
int min_tree[3*SIZE];
int max_tree[3*SIZE];
int arr[SIZE];
void init(int s, int e, int node) {
    if(s == e)  {
        min_tree[node] = arr[s];
        max_tree[node] = arr[s];
        return;
    }
    int mid = (s + e) / 2;
    init(s, mid, node*2);
    init(mid+1, e, node*2+1);
    min_tree[node] = min(min_tree[node*2], min_tree[node*2+1]);
    max_tree[node] = max(max_tree[node*2], max_tree[node*2+1]);
}
ll min_num(int s, int e, int l, int r, int node) {
    if (l > e || r < s) return INF;
    if (l <= s && e <= r)   return min_tree[node];
    int mid = (s+e) / 2;
    return min(min_num(s, mid, l, r, node*2), min_num(mid+1, e, l, r, node*2+1));
}
ll max_num(int s, int e, int l, int r, int node) {
    if(l > e || r < s)  return 0;
    if(l <= s && e <= r)    return max_tree[node];
    int mid = (s+e)/2;
    return max(max_num(s, mid, l, r, node*2), max_num(mid+1, e, l, r, node*2+1));
}
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
    }
    init(1, N, 1);
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        cout << min_num(1, N, a, b, 1) << " " << max_num(1, N, a, b, 1) << "\n";
    }
    return 0;
}
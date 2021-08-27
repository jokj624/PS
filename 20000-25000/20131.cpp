//AC
//BOJ 20131 트리 만들기
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
#define SIZE 500001
vector<int> v;
vector<int> graph[SIZE];
int check[SIZE];
priority_queue<int> pq;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, num;
    cin >> N;
    for(int i=0; i<N-2; i++) {
        cin >> num;
        v.push_back(num);
        check[num] += 1;
    }
    for(int i=1; i<=N; i++) {
        if(!check[i])   pq.push(i);
    }
    for(int i=0; i<N-2; i++) {
        int n = pq.top();
        pq.pop();
        if(v[i] < n) {
            graph[v[i]].push_back(n);
        }
        else    graph[n].push_back(v[i]);
        check[v[i]] -= 1;
        if(!check[v[i]])    pq.push(v[i]);
    }
    if (!pq.empty()) {
        int n = pq.top();
        pq.pop();
        graph[1].push_back(n);
    }
    for(int i=1; i<=N; i++) {
        sort(graph[i].begin(), graph[i].end());
        for(int temp : graph[i]) {
            cout << i << " " << temp << "\n";
        }
    }
    return 0;
}
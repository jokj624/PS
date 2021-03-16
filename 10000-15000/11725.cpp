//AC
//BOJ 11725 트리의 부모찾기
#include <iostream>
#include <vector>
#define NUM 101010
using namespace std;
vector<int> tree[NUM];
int parent[NUM];
void dfs(int root, int child){
    for(int i=0; i<tree[child].size(); i++){
        int node = tree[child][i];
        if(node!=root && parent[node]==0){
            parent[node] = child;
            dfs(child, node);
        }
    }
}
int main(){
    int N, a, b;
    cin >> N;
    for(int i=0; i<N-1; i++){
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    parent[1] = 1;
    dfs(0, 1);
    for(int i=2; i<=N; i++){
        printf("%d\n", parent[i]);
    }
    return 0;
}

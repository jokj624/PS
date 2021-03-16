//AC
//BOJ 10423  전기가 부족해
#include <iostream>
#include <vector>
#include <queue>
#define MAX 1010
using namespace std;
typedef pair<int, int> edge;
int elec[MAX];
bool visit[MAX];
vector<edge> node[MAX];
struct cmp{
	bool operator()(edge a, edge b){
		return a.second > b.second;
	}
};
long long int mst(int N, int K){
	long long int ans = 0;
	priority_queue<edge, vector<edge>, cmp > pq;	
	for(int i=0; i<K; i++){
		int start = elec[i];
		visit[start] = true;
		for(edge j : node[start]){
			pq.push(j);
		}
	}
	while(!pq.empty()){
		edge x = pq.top();
		pq.pop();
		if(visit[x.first])	continue;
		visit[x.first] = true;
		ans += x.second;
		for(edge j : node[x.first]){
			pq.push(j);
		}
	}
	return ans;
}
int main(){
	int N, M, K;
	cin >> N >> M >> K;
	for(int i=0; i<K; i++){
		scanf("%d", &elec[i]);
	}
	for(int i=0; i<M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		node[a].push_back({b,c});
		node[b].push_back({a,c});
	}
	long long int ans = mst(N, K);
	cout << ans;
	return 0;
}

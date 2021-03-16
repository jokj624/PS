//AC
//BOJ 1922 네트워크 연결 
//https://www.acmicpc.net/problem/1922 
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
vector<pair<int,int> > com[1001];
bool visit[1001]={false};
typedef pair<int, int> edge;
struct cmp{
	bool operator()(edge a, edge b){
		return a.second > b.second;
	}
};
int mst(int n, int start){
	long long int ans=0;
	priority_queue<edge, vector<edge>, cmp > pq;
	visit[start] = true;
	for(int j=0; j<com[start].size(); j++){
		pq.push(com[start][j]);
	}
	while(!pq.empty()){
		edge x = pq.top();
		pq.pop();
		if(visit[x.first]) 	continue;
		visit[x.first] = true;
		ans += x.second;
		for(int i=0; i<com[x.first].size();i++){
			pq.push(com[x.first][i]);
		}
	}
	return ans;
}
int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		com[a].push_back(make_pair(b,c));
		com[b].push_back(make_pair(a,c));
	}
	printf("%d",mst(n, 1));
	return 0;
}

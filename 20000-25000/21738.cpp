//AC
//SMUPC-E번
//BOJ 21738 얼음깨기 펭귄\
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#define INF 987654321
using namespace std;
int N, S, P, ans = INF;
vector<int> v[328001];
priority_queue<pair<int,int> > pq;   
int main(){
	cin >> N >> S >> P;
	for(int i=0; i<N-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int dist[N+1];
	fill(dist, dist+N+1, INF);
	pq.push({0, P});
	dist[P] = 0;
	while(!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		for(int i=0; i<v[here].size(); i++){
			int next = v[here][i];
			if(dist[next] > dist[here]+1){
				dist[next] = dist[here]+1;
				pq.push({-dist[next], next});
			}
		}
	}

	sort(dist, dist+S+1);
	printf("%d", N-(dist[0]+dist[1]+1));
	return 0;
}

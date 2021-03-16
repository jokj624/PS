//AC
//BOJ 5651 완전 중요한 간선
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 301
#define INF 987654321
using namespace std;

int main(){
	int K, N, M;
	cin >> K;
	while(K--){
		vector<pair<int, int> > p;
		int c[MAX][MAX]={0}, f[MAX][MAX]={0}, d[MAX];
		vector<int> v[MAX];
		int ans = 0;
		cin >> N >> M;
		for(int i=0; i<M; i++){
			int f, t, cost;
			scanf("%d %d %d", &f, &t, &cost);
			c[f][t] += cost;
			v[f].push_back(t);
			v[t].push_back(f);
			p.push_back({f, t});
		}
		while(1){
			int flow = INF;
			fill(d, d+N+1, -1);
			queue<int> q;
			q.push(1);
	
			while(!q.empty()){
				int x = q.front();
				q.pop();
				for(int y : v[x]){
					if(c[x][y]-f[x][y] > 0 && d[y] == -1){
						q.push(y);
						d[y] = x;
						if(y==N)	break;
					}
				}
			}
	
			if(d[N] == -1)	break;
	
			for(int i=N; i!=1; i=d[i]){
				flow = min(flow, c[d[i]][i] - f[d[i]][i]);
			}
		
			for(int i=N; i!=1; i=d[i]){
				f[d[i]][i] += flow;
				f[i][d[i]] -= flow;
			}
		}
	
		for(int i=0; i<p.size(); i++){
			int x = p[i].first;
			int y = p[i].second;
			
			queue<int> q2;
			fill(d, d+N+1, -1);
			q2.push(x);
			
			while(!q2.empty() && d[y] == -1){
				int cur = q2.front();
				q2.pop();
				for(int next : v[cur]){
					if(c[cur][next]-f[cur][next] > 0 && d[next] == -1){
						q2.push(next);
						d[next] = cur;
						if(next == y)	break;
					}
				}
			}
			if(d[y] == -1)	ans+=1;
		}
		
		printf("%d\n", ans);
	}	
	return 0;
}
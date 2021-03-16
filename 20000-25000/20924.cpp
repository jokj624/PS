//AC
//BOJ 20924 트리의 기둥과 가지

#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int> > v[200001];
int visit[200001];
int gi = 0, gidoong, ans = 0;
void dfs(int node, int pa, int R){
	visit[node] = 1;
	if(v[node].size() == 2){
		if(node == R){
			gidoong = node;
			return;
		}
		else{
			if(v[node][0].first != pa){
				gi += v[node][0].second;
				dfs(v[node][0].first, node, R);
			}
			else{
				gi += v[node][1].second;
				dfs(v[node][1].first, node, R);
			}
		}
	}
	else if(v[node].size() > 2){
		gidoong = node;
	}
	else if(v[node].size() == 1){
		if(node == R){
			gi += v[node][0].second;
			dfs(v[node][0].first, node, R);
		}
		else gidoong = node;
	}	
	return;
}
void maxCost(int node, int pa, int cur){
	visit[node] = 1;
	if(v[node].size() == 1){
		ans = max(ans, cur);
		return;
	}
	for(int i=0; i<v[node].size(); i++){
		pair<int, int> next = v[node][i];
		if(next.first == pa)	continue;
		if(!visit[next.first]){
			cur += next.second;
			maxCost(next.first, node, cur);
			cur -= next.second;
		}
	}
	
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N, R;
	cin >> N >> R;
	for(int i=0; i<N-1; i++){
		int a, b, d;
		cin >> a >> b >> d;
		v[a].push_back({b, d});
		v[b].push_back({a, d});
	}
	if(N == 1){
		cout << gi << " " << gidoong;
		return 0;
	}
	dfs(R, 0, R);
	maxCost(gidoong, gidoong, 0);
	cout << gi << " " << ans;
	return 0;
}
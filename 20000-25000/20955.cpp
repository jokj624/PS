//AC
//BOJ 20955 민서의 응급 수술
#include <iostream>
#include <vector>
using namespace std;
vector<int> v[101010];
bool visit[101010];
bool cycle[101010];
int N, M, cnt = 0;
void dfs(int s, int prev){
	visit[s] = true;
	for(int tmp : v[s]){
		if(!visit[tmp]){
			dfs(tmp, s);
		}
		else if(!cycle[tmp] && tmp != prev){
			cnt += 1;
		}
	}
	cycle[s] = true;
}
int main(){
	int ans = 0;
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int U, V;
		scanf("%d %d", &U, &V);
		v[U].push_back(V);
		v[V].push_back(U);
	}
	for(int i=1; i<=N; i++){
		if(!visit[i]){
			dfs(i, 0);
			ans += 1;
		}
	}
	printf("%d", ans-1+cnt);
	return 0;
}
//AC
//BOJ 9466 텀 프로젝트
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int v[101010];
bool visit[101010];
int pr[101010];
bool cycle[101010];
int cnt = 0;
void dfs(int s){
	visit[s] = true;
	if(!visit[v[s]]){
		pr[s] = v[s];
		dfs(v[s]);
	}
	else if(!cycle[v[s]]){
		for(int i=v[s]; i != s; i = pr[i]){
			cnt++;
		}
		cnt++;
	}
	cycle[s] = true;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cnt = 0;
		scanf("%d", &n);
		for(int i=1; i<=n; i++){
			scanf("%d", &v[i]);			
		}
		for(int i=1; i<=n; i++){
			if(!visit[i]){
				dfs(i);
			}
		}
		printf("%d\n", n-cnt);
		memset(visit, false, sizeof(visit));
		memset(cycle, false, sizeof(cycle));
	}
}
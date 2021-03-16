//AC
//BOJ 11377 열혈강호 3

#include <iostream>
#include <vector>
using namespace std;
vector<int> task[1001];
int d[1001];
bool c[1001];
bool dfs(int s){
	for(int i=0; i<task[s].size(); i++){
		int x =task[s][i];
		if(c[x])	continue;
		c[x] = true;
		
		if(d[x]==0 || dfs(d[x])){
			d[x] = s;
			return true;
		}
	}
	return false;
}
int main(){
	int n, m, k, cnt = 0;
	scanf("%d %d %d", &n, &m, &k);
	for(int i=1; i<=n; i++){
		int a, b;
		scanf("%d", &a);
		for(int j=0; j<a; j++){
			scanf("%d", &b);
			task[i].push_back(b);
		}
	}
	for(int i=1; i<=n; i++){
		if(dfs(i))	cnt++;
		fill(c, c+1001, false);
	}
	for(int i=1; i<=n; i++){
		if(dfs(i) && k > 0){
			cnt++;
			k--;
		}
		if(k <= 0)	break;
		fill(c, c+1001, false);
	}
	cout << cnt;
	return 0;
} 
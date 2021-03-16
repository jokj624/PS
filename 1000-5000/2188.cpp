//AC
//BOJ 2188 축사 배정
//https://www.acmicpc.net/problem/2188

#include <iostream>
#include <vector>
using namespace std;
vector<int> cow[201];
int d[201];
bool c[201];
bool dfs(int s){
	for(int i=0; i<cow[s].size(); i++){
		int x = cow[s][i];
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
	int n, m, cnt = 0;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		int a, b;
		cin >> a;
		for(int j=0; j<a; j++){
			cin >> b;
			cow[i].push_back(b);
		}
	}
	for(int i=1; i<=n; i++){
		if(dfs(i))	cnt++;
		fill(c, c+201, false);
	}
	cout << cnt;
	return 0;
} 

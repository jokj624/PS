//AC
//BOJ 1298 노트북의 주인을 찾아서
//https://www.acmicpc.net/problem/1298 

#include <iostream>
#include <vector>
using namespace std;
vector<int> v[101];
bool c[5001];
int d[5001];
bool labtop(int s){
	for(int i=0; i<v[s].size(); i++){
		int t = v[s][i];
		if(c[t])	continue; //이미 선택됨 
		c[t] = true;
		
		//비어있는 곳 or 이미 점유한 사람이 다른 
		//노트북 점유도 가능할 때 
		if(d[t]==0 || labtop(d[t])){
			d[t] = s;
			return true;
		}
	}
	return false;
}
int main(){
	int n, m, cnt=0;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
	}
	for(int i=1; i<=n; i++){
		if(labtop(i))	cnt++;
		fill(c, c+5001, false);
	}
	cout << cnt;
}

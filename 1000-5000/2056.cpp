//AC
//BOJ 2056 작업 
//https://www.acmicpc.net/problem/2056 
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int ind[10001]={0};
int time[10001]={0};
vector<int> task[10001];
int count_time(int n){
	queue<int> q;
	int d[10001]={0};
	int ans=0;
	for(int i=1; i<=n; i++){
		if(ind[i]==0){
			q.push(i);
			d[i] = time[i];
		}
	}
	for(int i=1; i<=n; i++){
		int x = q.front();
		q.pop();
		for(int j=0; j<task[x].size(); j++){
			int y = task[x][j];
			ind[y]--;
			d[y] = max(d[y],d[x]+time[y]);
			if(ind[y]==0){
				q.push(y);
			}
		}
	}
	for(int i=1; i<=n; i++){
		ans = max(d[i],ans);
	}
	return ans;
}
int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		int a, b;
		cin >> a >> b;
		time[i] = a;
		for(int j=0; j<b; j++){
			int c;
			cin >> c;
			task[c].push_back(i);
			ind[i]++;
		}
	}
	printf("%d", count_time(n));
	return 0;
}

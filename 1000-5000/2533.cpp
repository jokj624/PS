//AC
//BOJ 2533 사회망 서비스
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[1010100];
int dp[1010100][2];
int visit[1010100];
int N;
void makeDP(int root, int child){
	int notChoice = 1, choice = 0;
	if(visit[child])	return;
	for(int node : v[child]){
		if(node == root)	continue;
		makeDP(child, node);
		choice += dp[node][1];
		notChoice += min(dp[node][0], dp[node][1]);
	}
	visit[child] = true;
	dp[child][0] += choice;
	dp[child][1] += notChoice;
}
int main(){
	cin >> N;
	for(int i=0; i<N-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	makeDP(0, 1);
	cout << min(dp[1][0], dp[1][1]);
	return 0;
}

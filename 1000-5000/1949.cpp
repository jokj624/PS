//AC
//BOJ 1949 우수 마을
#include <iostream>
#include <vector>
using namespace std;
vector<int> maeul[10001];
int dp[10001][2];
int people[10001];
void dpTable(int root, int child){
	int notChoice = 0;
	int choice = 0;
	for(int node : maeul[child]){
		if(node == root)	continue;
		dpTable(child, node);
		notChoice += max(dp[node][1], dp[node][0]);
		choice += dp[node][0];
	}
	dp[child][0] = notChoice;
	dp[child][1] = choice + people[child];
}
int main(){
	int n;
	maeul[0].push_back(0);
	cin >> n;
	for(int i=1; i<=n; i++){
		scanf("%d", &people[i]);
	}
	for(int i=0; i<n-1; i++){
		int a,b;
		scanf("%d %d", &a, &b);
		maeul[a].push_back(b);
		maeul[b].push_back(a);
	}
	dpTable(0,1);
	cout << max(dp[1][0], dp[1][1]);
	return 0;
} 

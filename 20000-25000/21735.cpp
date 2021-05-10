//AC
//SMUPC-B번
//BOJ 21735 눈덩이 굴리기 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int arr[101];
ll ans;
int N, M;
void dfs(int x, ll sum, int cnt){
	if(cnt >= M){
		ans = max(ans, sum);
		return;
	}
	if(cnt + 1 <= M){
		dfs(x + 1, sum + arr[x+1], cnt + 1);
		dfs(x + 2, sum/2 + arr[x+2], cnt + 1);
	}
}
int main(){
	cin >> N >> M;
	for(int i=1; i<=N; i++){
		scanf("%d", &arr[i]);
	}
	dfs(0, 1, 0 );
	cout << ans;
	return 0; 
}

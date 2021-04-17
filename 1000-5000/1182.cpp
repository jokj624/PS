//AC
//BOJ 1182 부분 수열의 합

#include <iostream>
#include <vector>
using namespace std;
int N, S;
long long sum = 0, ans = 0;
vector<int> v;
void backTracking(int cur){
	if(cur == N)	return;	
	if(v[cur] + sum == S){
		ans += 1;
	}
	sum += v[cur];
	backTracking(cur+1);
	sum -= v[cur];
	backTracking(cur+1);
}
int main(){
	cin >> N >> S;
	for(int i=0; i<N; i++){
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	backTracking(0);
	cout << ans;
	return 0;
}

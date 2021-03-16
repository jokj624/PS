//AC
//BOJ 18783 Swapity Swapity Swap
#include <iostream>
#include <vector>
#define SIZE 100001
using namespace std;
int N, M, K;
int ST[SIZE][32], temp[SIZE], cow[SIZE];
struct Query{
	int s, e;
};
vector<Query> v;
void swap(int st, int end){
	int tmp = temp[st];
	temp[st] = temp[end];
	temp[end] = tmp;
}
void swapity(){
	for(Query q : v){
		int from = q.s;
		int to = q.e;
		for(int i = from; i < to; i++){
			swap(i, to);
			to--;
		}
	}
	for(int i=1; i<=N; i++){
		ST[i][0] = temp[i];
	}
	for(int i=1; i<31; i++){
		for(int j=1; j<=N; j++){
			ST[j][i] = ST[ST[j][i-1]][i-1];
		}
	}
}
void solve(){
	for(int i=30; i>=0; i--){
		if((1 << i) <= K){
			K -= (1<<i);
			for(int j=1; j<=N; j++){
				cow[j] = ST[cow[j]][i];
			}
		}
	}
	for(int i=1; i<=N; i++){
		printf("%d\n", cow[i]);
	}
	return;
}
int main(){
	cin >> N >> M >> K;
	for(int i=0; i<M; i++){
		int st, end;
		scanf("%d %d", &st, &end);
		v.push_back({st, end});
	}
	for(int i=1; i<=N; i++){
		cow[i] = i;
		temp[i] = i;
	}
	swapity();
	solve();
	return 0;
}
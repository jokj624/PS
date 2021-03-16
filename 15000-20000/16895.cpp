//AC
//BOJ 16895 님 게임 3
#include <iostream>
#include <vector>
using namespace std;
vector<int> stone;
int main(){
	int N, prev, ans = 0, tmp;
	cin >> N;
	for(int i=0; i<N; i++){
		int t;
		scanf("%d", &t);
		stone.push_back(t);
		prev ^= t;
	}
	if(!prev){
		printf("0");
		return 0;
	}
	for(int i=0; i<N; i++){
		prev = 0;
		for(int j=0; j<N; j++){
			if(i == j)	continue;
			prev ^= stone[j];	
		}
		for(int j=stone[i]-1; j>=0; j--){
			tmp = prev;
			tmp ^= j;
			if(!tmp){
				ans += 1;
			}
		}
	}
	cout << ans;
	return 0;
}
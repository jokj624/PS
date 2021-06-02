//AC
//BOJ 21872 deque game
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	int G, K, L;
	cin >> G;
	scanf("%d %d", &K, &L); // K = 종류, L = 층 
	while(G--){
		int N, M;
		string y, s;
		scanf("%d", &N);	// N = 연돌 크기, M = 세순 크기
		cin >> y;
		scanf("%d", &M);
		cin >> s;
		if(N < M){
			if(K > 1) printf("Y\n"); // 가지고 있는 층이 더 낮으면 만들 수 있는 블록 많음
			else if(K == 1)	printf("YS\n");
		}
		else if(N > M){  
			if(K > 1)	printf("S\n");
			else if(K == 1)	printf("YS\n");
		}
		else if(N == M ){   // 가지고 있는 층이 같을 때
			printf("YS\n");
		}
	}
	return 0;
}

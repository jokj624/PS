//AC
//BOJ 11070 피타고라스 기댓값
//https://www.acmicpc.net/problem/11070 
include <iostream>
using namespace std;
int expectation(int win, int lose){
	float f, s, a;
	int aws;
	s = win*win;
	a = lose*lose;
	f = (s/(s+a));
	aws = f * 1000;
	return aws;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int win[1000] = {0};
		int lose[1000] = {0};
		int n,m, a, b, s1,s2, max_score=0, min_score = 1000000000;
		scanf("%d %d", &n, &m);
		for(int i=0; i<m; i++){
			scanf("%d %d %d %d", &a, &b, &s1, &s2);
			win[a] += s1;
			lose[a] += s2;
			win[b] += s2;
			lose[b] += s1;
		}
		int temp;
		for(int i=1; i<=n; i++){
			if(win[i] == 0 && lose[i] == 0){
				temp = 0;
			}
			else 	temp = expectation(win[i], lose[i]);
			if(max_score < temp)	max_score = temp;
			if(min_score > temp)	min_score = temp;
		}
		printf("%d\n%d\n", max_score, min_score);
	}
	return 0;
}

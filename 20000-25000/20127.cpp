//AC
//BOJ 20127 Y-수열
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int searchIdx(int N, int ck){
	int idx = 0;
	for(int i=0; i<N-1; i++){
		if(ck){
			if(v[i] < v[i+1]){
				idx = i+1;  //반전되는 index 찾기
				break;
			}
		}
		else{
			if(v[i] > v[i+1]){
				idx = i+1;  //반전되는 index 찾기
				break;
			}
		}
	}
	return idx;
}
int main(){
	int N, ck=0, idx = 0, cnt = 1, prev = 0;
	cin >> N;

	for(int i=0; i<N; i++){
		int n;
		scanf("%d", &n);
		v.push_back(n);
		if(i == 1){
			if(v[i] >= v[i-1]){
				prev = 0;  // 전체 수열 정렬 확인 - 증가 수열
				cnt++;
			}
			else if(v[i] <= v[i-1]){
				prev = 1;  // 감소 수열
				cnt++;
			}
		}
		else if(i > 1){
			if(v[i] >= v[i-1] && !prev) 	cnt++;
			else if(v[i] <= v[i-1] && prev)	cnt++;  // 0 - 1 비교 결과에 따라 카운트
		}
	}
	if(cnt == N || N == 1){   // 시작 수열이 증가 수열이거나 감소 수열이면 0, 원소 1개라면 0 출력
		printf("0");
		return 0;
	}
	cnt = 1;
	for(int i=1; i<N; i++){
		if(v[i] <= v[i-1])	cnt++;
	}   // 같은 것이 있는 감소 수열 검사 
	
	if(cnt == N){
		printf("0");
		return 0;
	}
	
	if(v[N-1] < v[0])	ck = 0;   // 증가 수열
	else if(v[N-1] > v[0]) 	ck = 1; 	// 감소 수열
	else{
		ck = 2;
		int fir = searchIdx(N, 0);
		int sec = searchIdx(N, 1);
		if(fir < sec){
			idx = fir;
			ck = 0;
		}
		else{
			idx = sec;
			ck = 1;
		}
	}
	if(ck == 0 || ck == 1){
		idx = searchIdx(N, ck);
	}
	
	if(ck){   // 감소 수열 확인
		for(int i=idx; i<N-1; i++){	
			if(v[i] < v[i+1]){
				printf("-1");
				return 0;
			}
		}		
		for(int i=0; i<idx-1; i++){
			if(v[i] < v[i+1]){
				printf("-1");
				return 0;
			}
		}
	}
	else {   // 증가 수열
		for(int i=idx; i<N-1; i++){
			if(v[i] > v[i+1]){
				printf("-1");
				return 0;
			}
		}
		for(int i=0; i<idx-1; i++){
			if(v[i] > v[i+1]){
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d", idx);
	return 0;
}

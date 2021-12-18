//AC
//BOJ 20921 그렇고 그런 사이
#include <iostream>
#include <vector>
using namespace std;
int N, K;
int arr[4245];
void swap(int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
int main(){
	int tmp = 0;
	scanf("%d %d", &N, &K);                       
	for(int i=0; i<N; i++){
		arr[i] = i+1;
//		if(i != 0)	tmp += N-i;
	}
	if((N*(N-1))/2 == K){
		for(int i=N-1; i>=0; i--){
			printf("%d ", arr[i]);
		}
		return 0;
	}
	if(tmp < K){
		int idx = 0;
		while(tmp < K){
			if(idx == N-1)	idx = 0;
			if(arr[idx] < arr[idx+1]){
				swap(idx, idx+1);
				tmp += 1;
			}
			idx += 1;
		}
	}
	
	for(int i=0; i<N; i++){
		printf("%d ", arr[i]);
	}
}

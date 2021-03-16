//AC
//11004 K번째 수 (Quick Select)
#include <iostream>
#include <random>
#include <time.h>
#define SIZE 5000001
using namespace std;
default_random_engine generator;
int arr[SIZE];
int N, K;
void swap(int a, int b){
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}
void quickSelect(int start, int end){
	if(start >= end)	return;
	uniform_int_distribution<int> dist1(start, end);
	int pivot = dist1(generator);  //random pivot 
	int pv;
	swap(pivot, end);  //pivot 마지막으로 
	pivot = end;
	int i = start;
	int j = end-1;
	while(i <= j){
		while(i < end && arr[i] <= arr[pivot]){
			i++;
		}
		while(j >= start && arr[j] >= arr[pivot]){
			j--;
		}
		if(i > j){
			swap(i, pivot);
		}
		else{
			swap(i, j);
		}
	}
	int idx = i + 1;
	if(idx > K){
		quickSelect(start, i-1);
	}
	else if(idx == K)	return;
	else{
		quickSelect(i+1, end);
	}
	return;
}
int main(){
	scanf("%d %d", &N, &K);
	srand(time(NULL));
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
	}
	quickSelect(0, N-1);
	printf("%d", arr[K-1]);
	return 0;
}
//AC
//BOJ 2263 트리의 순회
#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 101010
using namespace std;
int N;
int in[SIZE];
int post[SIZE];
int idx[SIZE];
void makeTree(int inStart, int inEnd, int postStart, int postEnd){
	if(inStart > inEnd || postStart > postEnd)	return;
	printf("%d ", post[postEnd]);
	makeTree(inStart, idx[post[postEnd]]-1, postStart, postStart + (idx[post[postEnd]]-inStart) - 1 );
	makeTree(idx[post[postEnd]] + 1, inEnd, postStart + (idx[post[postEnd]] - inStart) , postEnd -1);
}

int main(){
	cin >> N;
	for(int i=1; i<=N; i++){
		scanf("%d", &in[i]);
	}
	for(int i=1; i<=N; i++){
		scanf("%d", &post[i]);
	}
	for(int i=1; i<=N; i++){
		idx[in[i]] = i;
	}
	makeTree(1, N, 1, N);

	return 0;
}

//AC
//BOJ 2912 백설공주와 난쟁이
#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 301010
using namespace std;
vector<int> idx[SIZE];
int arr[SIZE],  tree[SIZE*4];
int N, C;
void make(int node, int left, int right){
	if(left == right){
		tree[node] = arr[left];
		return;
	}
	int mid = (left+right) / 2;
	make(node*2, left, mid);
	make(node*2+1, mid+1, right);
	int lc = tree[node*2];
	int cnt = upper_bound(idx[lc].begin(), idx[lc].end(), right)-lower_bound(idx[lc].begin(), idx[lc].end(), left)-1; 
	if(cnt >= (right-left+1)/2) {
		tree[node] = lc;
		return;
	}
	lc = tree[node*2+1];
	cnt = upper_bound(idx[lc].begin(), idx[lc].end(), right)-lower_bound(idx[lc].begin(), idx[lc].end(), left)-1; 
	if(cnt >= (right-left+1)/2){
		tree[node] = lc;
		return;
	} 
	tree[node] = -1;
}
int segTree(int node, int left, int right, int start, int end){
	if(right<start || end < left)	return 0;
	if(start >= left && right >= end){
		int cnt = upper_bound(idx[tree[node]].begin(), idx[tree[node]].end(), right)-lower_bound(idx[tree[node]].begin(), idx[tree[node]].end(), left)-1; 
		if(cnt >= (right-left+1)/2){
			return tree[node];
		}
		else	return 0;
	}
	int mid = (start + end) / 2;
	int one = segTree(node*2 , left, right, start, mid);
	if(one > 0)	return one;
	int two = segTree(node*2+1, left, right, mid+1, end);
	if(two > 0)	return two;
	return 0;
}
int main(){
	int M, a, b;
	scanf("%d %d" , &N, &C);
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
		idx[arr[i]].push_back(i);
	}
	for(int i=1; i<=C; i++){
		sort(idx[i].begin(), idx[i].end());
	}		
	make(1, 0, N-1);
	scanf("%d", &M);
	while(M--){
		scanf("%d %d", &a, &b);
		int ans = segTree(1, a-1, b-1, 0, N-1);
		if(ans > 0)	printf("yes %d\n", ans);
		else	printf("no\n");
	}
	return 0;
}

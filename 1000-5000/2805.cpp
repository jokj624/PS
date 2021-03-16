//AC
//BOJ 2805 나무 자르기 
//https://www.acmicpc.net/problem/2805 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> tree;
int cut(int m, int n,int mid){
	long long result=0;
	for(int i=0; i<n; i++){
		if(tree[i] > mid){
			result += (tree[i]-mid);
		}
	}
	if(result > m)	return 1;
	else if(result < m)	return 2;
	else	return 0;
}
int main(){
	int ans,n, m, left=0, right=0, mid;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		int temp;
		scanf("%d", &temp);
		tree.push_back(temp);
		right = max(temp, right);
	}
	int tree_ans = 0;
	while(left<=right){
		mid = (left+right)/2;
		ans = cut(m,n,mid);
		if(ans == 1){
			left = mid + 1;
			tree_ans = mid; 
		}
		else if(ans == 2){
			right = mid - 1;
		}
		else{
			printf("%d", mid);
			return 0;
		}
	}
	printf("%d", tree_ans);
	return 0;
}

//BOJ 2042 구간 합 구하기 
// https://www.acmicpc.net/problem/2042
//AC
#include <iostream>
using namespace std;
long long arr[1000001];
long long tree[3000002];
long long make(int left, int right, int node){
	if(left == right){
		return tree[node] = arr[left];
	}
	int mid = (left+right)/2;
	
	tree[node] += make(left, mid, node*2);
	tree[node] += make(mid+1, right, node*2+1);
	return tree[node];
}
long long sum(int node, int left, int right, long long start, long long end){
	if(right<start || end < left)	return 0; // 구간 밖
	if(start <= left && right <= end)	return tree[node];
	int mid = (left+right)/2;
	
	return sum(node*2, left, mid, start, end) + sum(node*2+1, mid+1, right, start, end); 
}

void update(int left, int right, int node, long long change, long long diff){
	if(!(left<=change && change <= right))	return; 
	tree[node]+=diff;
	if(left!=right){
		int mid = (left+right)/2;
		update(left, mid, node*2, change, diff);
		update(mid+1, right, node*2+1, change, diff);
	}
}
int main(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1; i<=n; i++){
		scanf("%lld", &arr[i]);
	}
	make(1,n,1);
	
	for(int i=0; i<m+k; i++){
		long long ck, a, b;
		scanf("%lld %lld %lld", &ck, &a, &b);
		if(ck == 1){
			long long diff = b-arr[a];
			arr[a] = b;
			update(1,n,1,a,diff);
		}
		else if(ck==2){
			printf("%lld\n", sum(1,1,n,a,b));
		} 
	}
}

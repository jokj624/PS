//BOJ 1849 Random Generator
//AC
#include <iostream>
using namespace std;
int real[201010];
int arr[201010];
int tree[900050];
int countIdx = 0;
int make(int left, int right, int node, int n, int tmp){
	if(left == right){
		if(node <= (tmp+n-1)){
			countIdx = max(countIdx, node);
			return tree[node] = arr[left];
		}
		else 	return tree[node] = 0;
	}
	int mid = (left+right)/2;
	tree[node] += make(left, mid, node*2, n, tmp);
	tree[node] += make(mid+1, right, node*2+1, n, tmp);

	return tree[node];
}
void update(int change, int diff){
	tree[change] -= diff;
	if(change == 1)	return;
	update(change/2, diff);
}
void segTree(int node, int right, int i, int num){
	if((node*2 > countIdx)){	
		real[i] = node-right+1;
		update(node, tree[node]);
		return;
	}
	if(num > tree[node*2]){
		num -= tree[node*2];
		segTree(node*2+1, right, i, num);
	}
	else if(num <= tree[node*2]){
		segTree(node*2, right,  i , num);
	}
}
int main(){
	int n, tmp = 1;
	cin >> n;
	while(tmp < n) { 	tmp *= 2;    }
	for(int i=1; i<=n; i++){
		scanf("%d", &arr[i]);
	}
	make(1, tmp, 1, n, tmp);
	for(int i=1; i<=n; i++){
		int a;
		scanf("%d", &a);
		segTree(1, tmp, i, a);
	}
	for(int i=1; i<=n; i++){
		printf("%d ", real[i]);
	}
	return 0;
}
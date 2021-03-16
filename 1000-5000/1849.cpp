//BOJ 1849 순열
//AC
#include <iostream>
using namespace std;
int real[101010];
int tree[400050];
int countIdx = 0;
int make(int left, int right, int node, int n, int tmp){
	if(left == right){
		if(node <= (tmp+n-1)){
			countIdx = max(countIdx, node);
			return tree[node] = 1;
		}
		else 	return tree[node] = 0;
	}
	int mid = (left+right)/2;
	tree[node] += make(left, mid, node*2, n, tmp);
	tree[node] += make(mid+1, right, node*2+1, n, tmp);

	return tree[node];
}
void update(int change, int diff){
	tree[change] += diff;
	if(change == 1)	return;
	update(change/2, diff);
}
void segTree(int node, int right, int idx, int num){
	if(tree[node] == num && (node*2 > countIdx)){	
		tree[node] = 0;
		real[node-right] = idx;
		update(node, -1);
		return;
	}
	if(num > tree[node*2]){
		if(num != 1) num -= tree[node*2];
		segTree(node*2+1, right, idx, num);
	}
	else if(num <= tree[node*2]){
		segTree(node*2, right, idx, num);
	}
}
int main(){
	int n, tmp = 1;
	cin >> n;
	while(tmp < n) { 	tmp *= 2;    }
	make(1, tmp, 1, n, tmp);

	for(int i=1; i<=n; i++){
		int a;
		scanf("%d", &a);
		segTree(1,tmp,i,a+1);
	}
	for(int i=0; i<n; i++){
		printf("%d\n", real[i]);
	}
	return 0;
}
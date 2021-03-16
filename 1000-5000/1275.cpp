//AC 
//BOJ 1275 커피숍2 
//https://www.acmicpc.net/problem/1275
#include <iostream>
using namespace std;
long long v[100001];
long long tree[500002];
long long make(int left, int right, int node){
	if(left==right){
		return tree[node]=v[left];
	}
	int mid = (left+right)/2;
	tree[node]+=make(left,mid,node*2);
	tree[node]+=make(mid+1,right, node*2+1);
	return tree[node];
}
long long sum(int node, int left, int right, long long start, long long end){
	if(right<start|| end<left)	return 0;
	if(start<=left && right <=end){
		return tree[node];
	}
	int mid = (left+right)/2;
	return sum(node*2, left,mid, start, end)+sum(node*2+1,mid+1,right,start, end);
}
void update(int left, int right, int node, long long change, long long diff){
	if(!(left<=change&&right>=change))	return;
	tree[node] += diff;
	if(left!=right){
		int mid = (left+right)/2;
		update(left, mid, node*2, change, diff);
		update(mid+1, right, node*2+1, change, diff);
	}
}
int main(){
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; i++){
		scanf("%lld", &v[i]);
	}
	make(1,n,1);
	long long x, y, a, b;
	while(q--){
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		if(x>=y){
			printf("%lld\n",sum(1, 1, n, y, x));
		}
		else{
			printf("%lld\n", sum(1,1,n,x,y));
		}
	//	if(q==1)	break;
		long long diff = b - v[a];
		v[a] = b;
		update(1,n,1,a,diff);
	}
	return 0;
}

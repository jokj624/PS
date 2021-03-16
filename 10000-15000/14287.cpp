//AC
//BOJ 14287 회사 문화 3
#include <iostream>
#include <vector>
#define MAX 101010
using namespace std;
vector<int> v[MAX];
const int SIZE = 1 << 18;
int cnt=0, in[MAX], out[MAX], tree[SIZE*2];
void dfs(int x){
	in[x] = cnt++;
	for(int a : v[x])	dfs(a);
	out[x] = cnt++; 
}
void update(int change, int diff){
	int n = change + SIZE;
	while(n>0){
		tree[n] += diff;
		n/=2;
	}
}
int segTree(int node, int left, int right, int st, int en){
	if(left > en || right < st)	return 0;
	if(left >= st && en >= right)	return tree[node];
	int mid = (left+right+1) / 2;
	return segTree(node*2, left, mid-1, st, en)+segTree(node*2+1, mid, right, st, en);
}
int main(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		int a;
		scanf("%d", &a);
		if(i!=1)	v[a].push_back(i);
	}
	dfs(1);
	for(int i=1; i<=m; i++){
		int q, x, w;
		scanf("%d", &q);
		if(q==1){
			scanf("%d %d", &x, &w);
			update(in[x], w);
		}
		else if(q==2){
			scanf("%d", &x);
			printf("%d\n",segTree(1, 0, SIZE-1, in[x], out[x]));
		}
	}
	return 0;
}
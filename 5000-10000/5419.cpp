//BOJ 5419 북서풍
//AC
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 75004
using namespace std;
struct Point{
	int x, y;
};
bool cmp(const Point &a, const Point &b){
	if(a.x == b.x) 	return a.y > b.y;
	return a.x < b.x;
}
Point arr[MAX];
int yy[MAX];
const int ST = 1 << 17;
int tree[ST*2];
void update(int change, int diff){
	int n = ST + change;
	while(n>0){
		tree[n] += diff;
		n/=2;
	}
}
long long segTree(int node, int nl, int nr, int start, int end){
	if(end < nl || nr < start) 	return 0;
	if(start <= nl && nr <= end) 	return tree[node];
	int mid = (nl + nr+1) / 2;
	return segTree(node*2, nl, mid-1, start, end)+segTree(node*2+1, mid, nr, start, end);
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, tmp=1;
		long long ans = 0;
		scanf("%d", &n);
		while(tmp < n) { tmp *= 2; }
		for(int i=0; i<n; i++){
			scanf("%d %d", &arr[i].x, &arr[i].y);
			yy[i] = arr[i].y;
		}
		sort(arr, arr+n,  cmp);
		sort(yy, yy+n);
		for(int i=0; i<n; i++){
			arr[i].y = lower_bound(yy, yy+n, arr[i].y)-yy;
		}
		for(int i=0; i<n; i++){
			ans += segTree(1, 0, ST-1, arr[i].y, ST-1);
			update(arr[i].y, 1);
		}
		printf("%lld\n", ans);
		fill(tree, tree+ST*2, 0);
	}
}
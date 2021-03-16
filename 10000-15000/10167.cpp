//AC
//BOJ 10167 금광
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX (3005 << 2)
using namespace std;
typedef long long ll;

struct Gold{
	int x, y, w;
};
bool cmp(const Gold &a, const Gold &b){
	if(a.x == b.x) 	return a.y < b.y;
	return a.x < b.x;
}
Gold arr[3005];
vector<int> yy;
ll tsum[MAX];
ll rsum[MAX];
ll lsum[MAX];
ll sum[MAX];
ll l_max(ll a, ll b){
	if(a>b) 	return a;
	else 	return b;
}
void update(int node, int left, int right, int w, int idx){
	if(right < idx || idx < left) 	return;
	if(left == right){
		tsum[node] += w;
		lsum[node] += w;
		rsum[node] += w;
		sum[node] += w;
		return;
	}
	int mid = (left+right)/2;
	update(node*2, left, mid, w, idx);
	update(node*2+1, mid+1, right, w, idx);
	tsum[node] = tsum[node*2]+tsum[node*2+1];
	rsum[node] = l_max(rsum[node*2+1], tsum[node*2+1]+rsum[node*2]);
	lsum[node] = l_max(lsum[node*2], tsum[node*2]+lsum[node*2+1]);
	sum[node] = l_max(l_max(sum[node*2], sum[node*2+1]), (lsum[node*2+1]+rsum[node*2]));
}
ll segTree(int node, int left, int right, int st, int en){
	if(right < st || left > en)	return 0;
	if(left <= st && right >= en){
		return sum[node];
	}
	int mid = (left+right)/2;
	return l_max(segTree(node*2, left, mid, st, en), segTree(node*2+1, mid+1, right, st, en));
}
int main(){
	int n;
	ll ans = 0, y_idx;
	cin >> n;
	for(int i=0; i<n; i++){
		int a, b, c;
		scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].w);
		yy.push_back(arr[i].y);
	}
	sort(arr, arr+n, cmp);
	sort(yy.begin(), yy.end());
	yy.erase(unique(yy.begin(), yy.end()), yy.end());
	for(int i=0; i<n; i++){
		arr[i].y = lower_bound(yy.begin(), yy.end(), arr[i].y)-yy.begin();
	}
	y_idx = yy.size();
	for(int i=0; i<n; i++){
		fill(tsum, tsum+MAX, 0);
		fill(sum, sum+MAX, 0);
		fill(lsum, lsum+MAX, 0);
		fill(rsum, rsum+MAX, 0);
		if(i>0 && arr[i].x == arr[i-1].x)	continue;
		for(int j = i; j<n; j++){
			update(1, 0, y_idx-1, arr[j].w, arr[j].y);
			if(j != n-1 && arr[j+1].x == arr[j].x)	continue;
			ans = l_max(ans, segTree(1, 0, y_idx-1, 0, y_idx-1));
		}
	}
	printf("%lld\n", ans);
	return 0;
}
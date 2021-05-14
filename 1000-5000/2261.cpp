//AC
//BOJ 2261 가장 가까운 두 점
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define SIZE 101010
using namespace std;
typedef long long ll;
int N;
ll ans = 2e9+1;
struct Point{
	int x;
	int y;
};
Point pnt[SIZE];
bool cmpx(const Point& p1, const Point& p2){
	return p1.x < p2.x;
}
bool cmpy(const Point& p1, const Point& p2){
	return p1.y < p2.y;
}
ll getDist(Point i, Point j){
	return (i.x-j.x)*(i.x-j.x) + (i.y-j.y)*(i.y-j.y); 
}

ll min(ll a, ll b){
	return a > b ? b : a;
}
void minSubDist(int l, int r){
	if(l==r){
		ans = 2e9+1;
		return;
	}
	int mid = (l+r) >> 1;
	if((r-l+1)<=3){
		ll d2 = getDist(pnt[l], pnt[r]);
		if((r-l+1) == 2){
			ans = min(ans, d2);
			return;
		}
		else if((r-l+1) == 3){
			ll d1 = getDist(pnt[l], pnt[mid]);
			ll d3 = getDist(pnt[mid], pnt[r]);
			ans = min(min(ans, d1), min(d2, d3));
			return;
		}
	}
	minSubDist(l, mid);
	ll m1 = ans;
	minSubDist(mid+1, r);
	ll m2 = ans;
	ll tempDist = 0;
	
	ans = min(m1, m2);
	if(ans == 0)	return;
	vector<Point> canPnt;
	for(int i=l; i<=r; i++){
		int differ = pnt[mid].x - pnt[i].x;
		differ *= differ;
		if(differ < ans)	canPnt.push_back(pnt[i]);
	}
	sort(canPnt.begin(), canPnt.end(), cmpy);

	int len = canPnt.size();
	for(int i=0; i<len-1; i++){
		for(int j = i+1; j<len; j++){
			int differ = canPnt[i].y - canPnt[j].y;
			differ *= differ;
			if(differ < ans)	ans = min(ans, getDist(canPnt[i], canPnt[j]));
			else	break;
		}
	}
}
int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		scanf("%d %d", &pnt[i].x, &pnt[i].y);
	}
	sort(pnt, pnt+N, cmpx);
	minSubDist(0, N-1);
	cout << ans;
	return 0;
}

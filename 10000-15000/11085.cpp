//AC
//BOJ 11085 군사이동
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[1010];
struct edge{
	int start, end, cost;
};
vector<edge> maeul;
bool cmp(const edge &e1, const edge &e2){
	return e1.cost > e2.cost;
}
int Find(int x){
	if(x==parent[x])	return x;
	parent[x] = Find(parent[x]);
	return parent[x];
}
void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	if(x < y)	parent[y] = x;
	else	parent[x] = y;
}

int main(){
	int ans, p, w, c, v;
	cin >> p >> w >> c >> v;
	for(int i=0; i<w; i++){
		int a, b, c;
		cin >> a >> b >> c;
		maeul.push_back({a,b,c});
	}
	for(int i=1; i<=p; i++){
		parent[i] = i;
	}
	sort(maeul.begin(), maeul.end(), cmp);
	for(int i=0; i<w; i++){
		if(Find(maeul[i].start) != Find(maeul[i].end)){
			Union(Find(maeul[i].start), Find(maeul[i].end));
		}
		if(Find(c) == Find(v)){
			ans = maeul[i].cost;
			break;
		}
	}
	cout << ans;
	return 0;
}
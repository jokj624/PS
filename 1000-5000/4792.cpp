//AC
//BOJ 4792 레드블루 스패닝 트리

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int parent[1001];
struct edge{
	int start, end, weight;
};
bool cmp(const edge &e1, const edge &e2){
	if(e1.weight == e2.weight){
		return e1.start < e2.start;
	}
	else{
		return e1.weight < e2.weight;
	}
}
int Find(int x){
	if(x == parent[x])	return x;
	parent[x] = Find(parent[x]);
	return parent[x];
}
void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	if(x > y)	parent[x] = y;
	else 	parent[y] = x;
}
int minST(int m, vector<edge> v){
	int ans = 0;
	for(int i=0; i<m; i++){
		if(Find(v[i].start) != Find(v[i].end)){
			ans +=  v[i].weight;
			Union(Find(v[i].start), Find(v[i].end));
		}
	}
	return ans;
}
int maxST(int m, vector<edge> v){
	int ans = 0;
	for(int i=m-1; i>=0; i--){
		if(Find(v[i].start) != Find(v[i].end)){
			ans += v[i].weight;
			Union(Find(v[i].start), Find(v[i].end));
		}
	}
	return ans;
}
int main(){
	int n, m, k;
	edge tmp;
	while(1){
		scanf("%d %d %d", &n, &m, &k);
		if(n==0 && m==0 && k==0)	break;
		vector<edge> v;
		int f, t, w;
		char c;
		for(int i=1; i<=n; i++){
			parent[i] = i;
		}
		for(int i=0; i<m; i++){
			cin>> c >> f >> t;
			if(c == 'B')	w = 1;
			else if(c == 'R')	w = 0;
			tmp.start = f; 	tmp.end = t, tmp.weight = w;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end(), cmp);
		int minK = minST(m, v);
		for(int i=1; i<=n; i++){
			parent[i] = i;
		}
		int maxK = maxST(m, v);
		if(k >= minK && k<= maxK){
			printf("1\n");
		}
		else if(k<minK || k>maxK){
			printf("0\n");
		}
	}
	return 0;
}
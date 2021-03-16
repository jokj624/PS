//AC
//BOJ 17619 개구리 점프 
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101010
using namespace std;
typedef struct tong{
	int x, x2, idx;
};
int parent[MAX];
bool cmp(const tong &t1, const tong &t2){
	return t1.x < t2.x;
}
int Find(int a){
	if(parent[a] == a)	return a;
	parent[a] = Find(parent[a]);
	return parent[a];
}
void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a==b)	return;
	parent[b] = a;
}
int main(){
	vector <tong> t;
	int N, Q, a, b, c;
	tong temp;
	cin >> N >> Q;
	for(int i=1; i<=N; i++){
		scanf("%d %d %d", &a, &b, &c);
		temp.x = a; temp.x2 = b; temp.idx = i;
		t.push_back(temp);
		parent[i] = i;
	}
	sort(t.begin(), t.end(), cmp);
	for(int i=1; i<N; i++){
		if(t[i].x <= t[i-1].x2){
			Union(t[i-1].idx, t[i].idx);
			t[i].x2 = max(t[i-1].x2, t[i].x2);
		}
	}
	int start, end;
	for(int i=0; i<Q; i++){
		scanf("%d %d", &start, &end);
		if(Find(start) == Find(end)){
			printf("1\n");
		}
		else{
			printf("0\n");
		}
	}
	return 0;
}
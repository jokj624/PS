//AC
//BOJ 13334 철로
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
struct point {
	int x;
	int y;
};
struct compare {
	bool operator()(const point& p1, const point& p2) {
		if(p1.y == p2.y)	return p1.x > p2.x;
		else	return p1.y > p2.y;
	}  // 끝점 기준 정렬
};
struct cmp{
	bool operator()(const point& p1, const point& p2){
		return p1.x > p2.x;
	}
};  // 시작점 기준 정렬
priority_queue<point, vector<point>, compare> pq;  // 끝점 기준 정렬
priority_queue<point, vector<point>, cmp> spq; //시작점 기준 정렬 
int main()
{
	int N;
	vector<point> v;
	cin >> N;
	for(int i=0; i<N; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back({a, b});
		if(v[i].x > v[i].y)	swap(v[i].x, v[i].y);
	}
	int d;
	cin >> d;
	for(point tmp: v){
		pq.push(tmp);
	}
	int ans = 0, count = 0;
	while(!pq.empty()){
		if(pq.top().x + d < pq.top().y){   //현재 x-y 거리가 d보다 크면 필요 없음
			pq.pop();
		}
		else{
			while(!spq.empty() && spq.top().x + d < pq.top().y){
				spq.pop();   //현재 y값이 정답큐에 있는 기존 철로 x값+d(거리) 보다 크다면 기존 철로 시작점 x를 버리고 계속해서 증가시킨다.
			}
			spq.push(pq.top()); // 현재 x-y를 정답 큐에 넣는다.
			pq.pop();
			int len = spq.size();   
			ans = max(ans, len);  // 매번 사이즈 비교하여 최댓값 갱신
		}
	}
	printf("%d", ans);
	return 0;
}


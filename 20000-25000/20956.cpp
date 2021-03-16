//WA ...
//BOJ 20956 아이스크림 도둑 지호

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<pair<int, int> > v;
deque<pair<int, int> > dq[101010];

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
	return a.first > b.first;
}

int main(){
	int N, K, t;
	scanf("%d %d", &N, &K);
	for(int i=1; i<=N; i++){
		scanf("%d", &t);
		v.push_back({t, i});
	}
	int idx = 0, prev;
	sort(v.begin(), v.end(), cmp);  //아이스크림 양이 큰 순서대로 정렬
	dq[0].push_back({v[0].first, v[0].second});
	prev = v[0].first;
	for(int i=1; i<N; i++){    //deque에 양이 많은 거 부터 넣어줌 양이 똑같은 아이스크림은 계속 같은 deque에 넣는다.
		if(v[i].first == prev){
			dq[idx].push_back({v[i].first, v[i].second});
			prev = v[i].first;
		}
		else{
			idx += 1;
			dq[idx].push_back({v[i].first, v[i].second});
			prev = v[i].first;
		}
	}
	idx = 0;
	int ck = 0, cur = 0, fir, sec; // ck == 0 이면 안 뒤집힌 상태  앞에서 빼기 , ck == 1 뒤집힌 상태 뒤에서 빼기
	while(K--){
		if(!ck){
			if(dq[idx].size() > 0){
				fir = dq[idx].front().first;
				sec = dq[idx].front().second;
				printf("%d\n", sec);
				dq[idx].pop_front();
			}
			else{  //현재 index deque이 비었으면 다음 deque으로 넘긴다.
				idx += 1;
				fir = dq[idx].front().first;
				sec = dq[idx].front().second;
				printf("%d\n", sec);
				dq[idx].pop_front();
			}
			if(fir % 7 == 0){   //7의 배수면 뒤집어 준다 상태 변동
				ck = 1;
			}
			continue;
		}
		else{
			if(dq[idx].size() > 0){  //뒤집힌 상태에서는 back부터 뺀다.
				fir = dq[idx].back().first;
				sec = dq[idx].back().second;
				printf("%d\n", sec);
				dq[idx].pop_back();
			}
			else{ 
				idx += 1;
				fir = dq[idx].back().first;
				sec = dq[idx].back().second;
				printf("%d\n", sec);
				dq[idx].pop_back();
			}
			if(fir % 7 == 0){
				ck = 0;
			}
		}
	}
	return 0;
}


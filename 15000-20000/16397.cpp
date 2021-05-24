//AC
//BOJ 16397 탈출
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define SIZE 101010
using namespace std;
bool visit[SIZE];
queue<pair<int, int> > q;
int main(){
	int N, T, G, ans=0;
	cin >> N >> T >> G;
	q.push({N, 0}); // N, Button
	visit[N] = true;
	while(!q.empty()){
		pair<int, int> x = q.front();
		q.pop();
		if(x.first == G){
			// 종료
			if(x.second <= T)	printf("%d", x.second);
			else	printf("ANG");
			return 0;
		}
		else{
			int num = x.first;
			if(x.first+1 <= 99999){
				if(!visit[x.first+1]){
					q.push({x.first+1, x.second+1});
					visit[x.first+1] = true;  // 버튼 A
				}
			}

			if((x.first*2) <= 99999){  // 버튼 B
				int tmp = x.first*2;
				int cnt = 0;
				if(tmp == 0)	continue;
				while(tmp > 0){
					tmp /= 10;
					cnt += 1;
				}			
				x.first *= 2;
				if(cnt == 5)	x.first -= 10000;
				else if(cnt == 4)	x.first -= 1000;
				else if(cnt == 3)	x.first -=100;
				else if(cnt == 2)	x.first -=10;
				else if(cnt == 1)	x.first -=1;
				if(!visit[x.first]){
					visit[x.first] = true;
					q.push({x.first, x.second+1});
				}
			}

		}
	}
	if(!visit[G])	printf("ANG");
	return 0;
}

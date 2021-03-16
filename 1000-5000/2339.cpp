//BOJ 2339 석판 자르기
//아니 왜 안되지 ??
#include <iostream>
#include <vector>
using namespace std;
int arr[25][25];
int N;
long long int recur(int direction,int sx,int sy,int ex,int ey){
	int boseok = 0, bad = 0;
	long long int ans = 0;
	vector<pair<int, int> > v;
	for(int i = sx; i<ex; i++){
		for(int j=sy; j<ey; j++){
			if(arr[i][j] == 2)	boseok++;
			else if(arr[i][j] == 1){
				bad++;
				v.push_back({i, j});
			}	
		}
	}
	if(boseok == 0) 	return 0;
	if(boseok == 1 && bad == 0) 	return 1; 
	if(bad == 0) 	return 0;
	int tmp = 0;
	if(direction != 1) {
			//세로 방향 
		for(int i = 0; i<v.size(); i++){	
			for(int j=sx; j<ex; j++){
				if(arr[j][v[i].second] == 2)	tmp++;
			}
			if(tmp > 0)		continue;
			ans += 	recur(1, sx, sy, ex, v[i].second) * recur(1, sx, v[i].second+1, ex, ey );
		}
	}
	tmp = 0; 
	if(direction != 2) {
			//가로 방향 
		for(int i=0; i<v.size(); i++){
			for(int j=sy; j<ey; j++){
				if(arr[v[i].first][j] == 2)	tmp++;
			}		
			if(tmp > 0)		continue;
			ans += 	recur(2, sx, sy, v[i].first, ey) * recur(2, v[i].first+1 ,sy, ex, ey );
		}
	}
	return ans;
}
int main(){
	int b = 0, bad = 0;
	long long int ans = 0;
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &arr[i][j]);
			if(arr[i][j] == 2)	b++;
			else if(arr[i][j] == 1) bad++;
		}
	}
	if(b==1 && bad==0){
		printf("1");
		return 0;
	}
	ans = recur(0, 0, 0, N, N);
	if(ans == 0)	 printf("-1");
	else 	printf("%lld", ans);
	return 0;
}
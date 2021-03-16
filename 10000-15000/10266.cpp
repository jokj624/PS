//AC
//BOJ 10266	시계 사진들 
#include <iostream>
#include <vector>
#define SIZE 360000
using namespace std;
vector<int> time(SIZE*2, 0);
vector<int> time2(SIZE, 0);
vector<int> failFunc(){
	int j = 0;
	vector<int> fail(SIZE, 0);
	for(int i=1; i<SIZE; i++){
		while(j != 0 && time2[i] != time2[j]){
			j = fail[j-1];
		}
		if(time2[i] == time2[j]){
			j += 1;
			fail[i] = j;
		}
	}
	return fail;
}
void solve(){
	vector<int> fail = failFunc();
	int j = 0;
	for(int i=0; i<SIZE*2; i++){
		while(j != 0 && time[i] != time2[j]){
			j = fail[j-1];
		}
		if(time[i] == time2[j]){
			if(j == (SIZE-1)){
				printf("possible");
				return;
			}
			else	j++;
		}
	}
	printf("impossible");
	return;
}
int main(){
	int n, a;
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d", &a);
		time[a] = 1;
		time[a+SIZE] = 1;
	}
	for(int i=0; i<n; i++){
		scanf("%d", &a);
		time2[a] = 1;
	}
	solve();
	return 0;
}
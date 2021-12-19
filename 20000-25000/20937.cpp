//AC
//BOJ 20937 떡국
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[500005];
int main(){
	int N, a, cnt = 0;
	cin >> N;
	if(N==1){
		printf("1");
		return 0;
	}
	for(int i=0; i<N; i++){
		scanf("%d", &a);
		arr[a]+=1;
	}
	for(int i=1; i<=50000; i++){
		cnt = max(cnt, arr[i]);
	}
	printf("%d", cnt);
	return 0;
	
}

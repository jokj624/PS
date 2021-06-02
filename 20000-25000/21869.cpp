//AC
//BOJ 21869 Maximum Bishop
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int N, a = 1;
	cin >> N;
	if(N==1){
		printf("1\n");
		printf("1 1");
		return 0;
	}
	cout << N + (N-2) << "\n";
	for(int i=1; i<=N; i++){
		printf("%d %d\n", i, 1);
	}
	for(int i=2; i<N; i++){
		printf("%d %d\n",i ,N);
	}
	return 0;
}

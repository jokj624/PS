//AC
//BOJ 1648 격자판 채우기
#include <iostream>
using namespace std;
int arr[225][1 << 15];
int main(){
	int N, M, state = 0;
	cin >> N >> M;
	arr[N*M][0] = 1;
	for(int i=N*M-1; i>=0; i--){
		for(int state = 0; state < 1<<M; state++){
			if(state & 1){   //이미 채워져있음 -> 그 전 값이 답
				arr[i][state] += arr[i+1][state >> 1];
			}
			else{  //수직 채우기
				arr[i][state] += arr[i+1][state>>1 | 1<<M-1];
			}  
			if(i%M != M-1 && !(state & 3)){  //수평 채우기
				arr[i][state] += arr[i+1][(state>>1)|1];
			}
			arr[i][state] %= 9901;
		}
		
	}
	cout << arr[0][0];
	return 0;
}
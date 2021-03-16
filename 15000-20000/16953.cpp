//AC 
//BOJ 16953 A -> B
#include <iostream>
using namespace std;
int main(){
	int A, B, cnt=1, check=1;
	cin >> A >> B;
	while(A < B){
		if(B%10 == 1){
			B /= 10;
			cnt++;
		}
		else if(!(B%2)){
			B /= 2;
			cnt++;
		}
		else{
			check = 0;
			break;
		}
	}             
	if(check & A==B){
		printf("%d", cnt);
	}                     
	else{
		printf("-1");
	}      
	return 0;
}
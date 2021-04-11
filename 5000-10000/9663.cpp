//AC
//BOJ 9663 N-Queen

#include <iostream>
using namespace std;
int board[16];
int ans = 0, n;
int check(int count){
	for(int i=0; i<count; i++){
		if(board[count] == board[i] || count - i == abs(board[count]-board[i])){
			return 0;
		}
	}
	return 1;
}
void queen(int count){
	if(count == n){
		ans += 1;
		return;
	}
	for(int i=0; i<n; i++){
		board[count] = i;
		if(check(count)){
			queen(count+1);
		}
	}
}
int main(){
	cin >> n;
	queen(0);
	cout << ans;
	return 0;
}
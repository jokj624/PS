//AC
//SMUPC-A번
//BOJ 21734 SMUPC의 등장
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	string s;
	
	cin >> s;
	for(int i=0; i<s.size(); i++){
		int n = putchar(s[i]);
		int sum = 0;
		while(n > 0){
			sum += (n%10);
			n /= 10;
		}
		for(int j=0; j<sum-1; j++){
			cout << s[i];
			
		} cout << "\n";
	}
	return 0;
}

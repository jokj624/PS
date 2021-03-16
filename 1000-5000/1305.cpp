//AC
//BOJ 1305 광고
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string str;
int make(int n){
	vector<int> fail(n, 0);
	int j = 0;
	for(int i=1; i<n; i++){
		while(j > 0 && str[i] != str[j]){
			j = fail[j-1];
		}
		if(str[i] == str[j]){
			j += 1;
			fail[i] = j;
		}
	}
	return fail[n-1];
}
int main(){
	int n;
	cin >> n;
	cin >> str;
	cout << n - make(n);
	return 0;
}
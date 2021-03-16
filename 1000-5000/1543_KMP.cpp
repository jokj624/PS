//AC
//BOJ 16916 부분 문자열 
#include <iostream>
#include <vector>
#include <string>
using namespace std;
string str, pattern;
vector<int> make(){
	vector<int> checkSub(pattern.size(), 0);
	int i = 0;
	for(int j = 1; j<pattern.size(); j++){
		while(i > 0 && pattern[j] != pattern[i]){
			i=checkSub[i-1];
		}
		if(pattern[j] == pattern[i]){
			i += 1;
			checkSub[j] = i;
		}
	}
	return checkSub;
}
int checkStr(){
	vector<int> sub = make();
	int i = 0, cnt = 0;
	for(char c : str){
		while(i > 0 && c != pattern[i]){
			i = sub[i-1];
		}
		if(c == pattern[i]){
			if(i == pattern.size()-1){
				cnt += 1;
				i = 0;
			}		
			else	i += 1;
		}
	}
	return cnt;
}
int main(){
	getline(cin, str);
	getline(cin, pattern);
	int n = checkStr();
	cout << n;
	return 0;
}
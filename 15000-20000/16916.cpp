//AC
//BOJ 16916 부분 문자열 
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
string str, pattern;
vector<int> make(){
	vector<int> checkSub(pattern.size(), 0);
	int i = 0;
	for(int j = 1; j<checkSub.size(); j++){
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
	int i = 0, check = 0;
	for(char c : str){
		while(i > 0 && c != pattern[i]){
			i = sub[i-1];
		}
		if(c == pattern[i]){
			if(i == pattern.size()-1){
				check = 1;
				i = sub[i];
			}		
			else	i += 1;
		}
	}
	if(check==1)	return 1;
	else 	return 0;
}
int main(){
	cin >> str;
	cin >> pattern;
	int n = checkStr();
	if(n == 1)	cout << "1";
	else 	cout << "0";
	return 0;
}
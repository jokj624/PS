//AC
//BOJ 4354 문자열 제곱
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int failFunction(string str){
	int j = 0;
	vector<int> fail(str.size(), 0);
	for(int i=1; i<str.size(); i++){
		while(j > 0 && str[i]!=str[j]){
			j = fail[j-1];
		}
		if(str[i] == str[j]){
			j += 1;
			fail[i] = j;
		}
	}
	return fail[str.size()-1];
}
int main(){
	while(1){
		string str;
		cin >> str;
		if(str[0] == '.')	break;
		int idx = failFunction(str);
		int len = str.size();
		if(len == (len-idx)){	
			printf("1\n");
			continue;
		}
		if(!(len % (len-idx))) 	printf("%d\n", len/(len-idx));
		else	printf("1\n");
	}
	return 0;
}
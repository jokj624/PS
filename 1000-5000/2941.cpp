//AC
//BOJ 2941 크로아티아 알파벳 
//https://www.acmicpc.net/problem/2941
#include <iostream>
#include <string>
using namespace std;
string str;
void check_string(){
	int idx = 0;
	int cnt = 0;
	while(idx <= str.size()){
		if(str[idx] == '\0')	break;
		if(str[idx] == 'c'){
			if(idx+1 < str.size() && (str[idx+1] == '=' || str[idx+1] =='-')){
				cnt++;
				idx+=2;
			}
			else{
				cnt++;
				idx++;
			}
		}
		else if(str[idx] == 'd'){
			if(idx+1 < str.size() && str[idx+1] == '-'){
				cnt++;
				idx+=2;
			}
			else if(idx+1 < str.size()&& str[idx+1] == 'z'){
				if(idx+2 < str.size() && str[idx+2] == '='){
					cnt++;
					idx+=3;
				}
				else{
					cnt++;
					idx++;
				}
			}
			else{
				cnt++;
				idx++;
			}
		}
		else if(str[idx] == 'l' || str[idx] =='n'){
			if(idx+1 < str.size() &&str[idx+1] == 'j'){
				cnt++;
				idx+=2;
			}
			else{
				cnt++;
				idx++;
			}
		}
		else if(str[idx] == 's' || str[idx] =='z'){
			if(idx+1 < str.size() &&str[idx+1] == '='){
				cnt++;
				idx+=2;
			}
			else{
				cnt++;
				idx++;
			}
		}
		else{
			cnt++;
			idx++;
		}
	}
	cout << cnt;
}
int main(){
	cin >> str;
	check_string();
}

//AC
//SMUPC-D번
//BOJ 21737 SMUPC 계산기
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#define INF 987654321
using namespace std;
char arr[501010];
char after[501010];
int main(){
	int N, ck = 0, check = 0;
	string s;
	cin >> N;
	cin >> s;
	int idx = 0;
	for(int i=0; i<s.size(); i++){
		if(s[i] == 'C')	check = 1;
	}
	if(!check){
		printf("NO OUTPUT");
		return 0;
	}
	int ans=0, is_number = 0, num = 0, real = 0;
	vector<int> v;
	char alpha[N+1];
	char prev;
	for(int i=0; i<s.size(); i++){
		if(s[i] >= '0' &&  s[i]<='9'){
			if(is_number == 1){
				num = num * 10;
				num = num + s[i] - 48;
			}
			else{
				num = s[i] - 48;
			}
			is_number= 1;
		}
		else{
			if(is_number == 1){
				v.push_back(num);
				num = 0;	
			}
			alpha[idx++] = s[i]; 
			is_number = 0;
		}
	}
	ans = v[0];
	int num_idx = 1;
	for(int i=0; i<idx; i++){
		if(alpha[i] == 'S'){
			ans -= v[num_idx++];
		}
		else if(alpha[i] == 'M'){
			ans *= v[num_idx++];
		}
		else if(alpha[i] == 'U'){
			ans /= v[num_idx++];
		}
		else if(alpha[i] == 'P'){
			ans += v[num_idx++];
		}
		else if(alpha[i] == 'C'){
			printf("%d ", ans);
		}
	}
	return 0;
}

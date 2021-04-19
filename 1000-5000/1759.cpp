//AC
//BOJ 1759 암호 만들기 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<char> v;
vector<int> combination;
int main(){
	int L, C;
	char c;
	cin >> L >> C;
	for(int i=0; i<C; i++){
		cin >> c;
		v.push_back(c);
		if(i < L)	combination.push_back(0);
		else	combination.push_back(1)	;
	}
	sort(v.begin(), v.end());
	do{
		string s;
		int moeum = 0, jaeum = 0;
		for(int i=0; i<C; i++){
			if(combination[i] == 0){
				s.push_back(v[i]);
				if(v[i] == 'a' || v[i] == 'i' || v[i] == 'e' || v[i] == 'o' || v[i] == 'u'){
					moeum += 1;
				}
				else 	jaeum += 1;
			}
		}
		if(moeum > 0 && jaeum >= 2){
			cout << s << "\n";
		}
	}while(next_permutation(combination.begin(), combination.end()));
}
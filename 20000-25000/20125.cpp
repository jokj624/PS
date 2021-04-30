//AC
//BOJ 20125 쿠키의 신체 측정
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	int N, c=0, left=0, right=0, legl = 0, legr = 0;
	int heartl, heartr;
	char ch;
	bool check = false;
	cin >> N;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> ch;
			if(ch == '*' && !check){
				heartl = i+1;
				heartr = j;
				check = true;
			}
			if(ch == '*' && check){
				if(i == heartl){
					if(j < heartr){
						left += 1;
					}
					if(j > heartr){
						right += 1;
					}
				}
				if(i > heartl){
					if(j == heartr)	c += 1;
					if(j < heartr)	legl += 1;
					if(j > heartr)	legr += 1;
				}
			}
		}
	}
	cout << heartl << " " << heartr << "\n";
	cout << left << " " << right << " " << c << " " << legl << " " << legr;
	return 0;
}

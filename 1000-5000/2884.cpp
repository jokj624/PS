//AC
//BOJ 2884 알람 시계
//https://www.acmicpc.net/problem/2884 

#include <iostream>
using namespace std;
int main(){
	int h, m;
	cin >> h >> m;
	if(m < 45){
		if(h!=0) 	h--;
		else{
			h = 23;
		}
		m = 60-(45-m);
		cout << h <<" " <<m; 
	}
	else{
		m -= 45;
		cout << h << " " << m;
	}
}

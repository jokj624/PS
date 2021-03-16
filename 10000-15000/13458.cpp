//AC
//BOJ 13458 시험 감독 
//https://www.acmicpc.net/problem/13458 
#include <iostream>
using namespace std;
int main(){
	int people[1000000] = {0};
	int n, master, sub;
	long long real = 0;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> people[i];
	}
	cin >> master >> sub;
	for(int i=0; i<n; i++){
		people[i] -= master;
		real++;
		if(people[i]>0){	
			if(!(people[i] % sub))	real += (people[i]/sub);
			else	real = real+(people[i]/sub)+1;
	}
	}
	cout << real << endl;
	return 0;
}

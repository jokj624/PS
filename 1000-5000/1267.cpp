//AC
//BOJ 1267 핸드폰 요금  
//https://www.acmicpc.net/problem/1267
#include <iostream>
using namespace std;
int main(){
	int n, y=0, m=0;
	int arr[21]={0};
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	for(int i=0; i<n; i++){
		if(arr[i] < 30)	y+=10;
		else{
			int a = arr[i];
			y+= 10*(a/30) + 10;
		}
	}
	for(int i=0; i<n; i++){
		if(arr[i] < 60)	m+=15;
		else{
			int a = arr[i];
			m+= 15*(a/60) + 15;
		}
	}
	if(y==m)	cout << "Y M " << y;
	else{
		int minnum = min(y,m);
		if(minnum==y)	cout << "Y " << y;
		else	cout << "M " << m;
	}
	return 0;
}

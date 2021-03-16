//AC
//BOJ 2798 블랙잭 
// https://www.acmicpc.net/problem/2798
#include <iostream>
using namespace std;
int main(){
	int n, m;
	int arr[101];
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int min = 100000;
	for(int i=0; i<n; i++){
		for(int j=1; j<n; j++){
			for(int k=2; k<n; k++){
				int score;
				if(i!=j && j!=k && i!=k) 	score = arr[i] + arr[j] + arr[k];
				if(m == score){
					cout << m;
					return 0;
				}
				else if(score > m)	continue;
				else if((m-score) < min)	min = m-score;
			}
		}
	}
	cout << m-min;
	return 0;
}

//AC
//BOJ 16288 Passport Control
//https://www.acmicpc.net/problem/16288
#include <iostream>
#include <queue>
using namespace std;
queue<int> pass[101];
int main(){
	int n, passport;
	int arr[101];
	cin >> n >> passport;
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	for(int i=0; i<n; i++){
		bool check = false;
		for(int j=1; j<=passport; j++){
			if(pass[j].empty()){
				pass[j].push(arr[i]);
				check = true;
				break;
			}
			if(arr[i] > pass[j].back()){
				pass[j].push(arr[i]);
				check = true;
				break;
			}
		}
		if(check == false){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}

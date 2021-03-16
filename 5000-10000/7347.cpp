//AC
//BOJ 7347 플립과 시프트 
//https://www.acmicpc.net/problem/7347 
#include <iostream>
using namespace std;
void check(int arr[], int n){
   int c1 = 0, c2 = 0;
   for (int k = 1; k <=n ; k += 2) { // 홀수자 리 
        if (arr[k] == 1) {
            c1++;
        }
    }
    for (int l = 2; l <= n; l += 2) {
        if (arr[l] == 1) {
            c2++;
        }
    }
    if ((c1 - c2) == 1 || (c1 - c2) == 0 || (c1 - c2) == -1) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }

}
int main(){
	int t, n;
	int arr[32];
	cin >> t;
	while(t--){
		cin >> n; 
		for(int i=1; i<=n; i++){
			cin >> arr[i];
		}
		if((n%2))	cout << "YES" << "\n";
		else	check(arr, n);
	}
}


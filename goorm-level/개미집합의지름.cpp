#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	int n, d, count = 0;
	int arr[100010];
	
	cin >> n >> d;
	int l = 0, r = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	
	while ((l < n) && (r < n)) {
		if (arr[r] - arr[l] <= d) {
			r++;
		} else {
			count++;
			l++;
			r++;
		}
	}
	
	cout << count;
	return 0;
}

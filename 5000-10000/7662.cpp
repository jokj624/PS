//AC
//BOJ 7662 이중 우선순위 큐
//https://www.acmicpc.net/problem/7662
//multiset  
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		multiset<int> ms;
		int q, n;
		char c;
		cin >> q;
		while (q--) {
			scanf(" %c %d", &c, &n);
			if (c == 'I') {
				ms.insert(n);
			}
			else if (c == 'D') {
				if (ms.empty())	continue;
				 if (n == 1) {
				 	ms.erase(--ms.end());
				 }
				 else if (n == -1) {
					ms.erase(ms.begin());
				 }
			}
		}
		if (ms.empty()) {
			printf("EMPTY\n");
		}
		else {
			cout << *(--ms.end()) << " " << *(ms.begin()) << "\n";
		}
	}
	return 0;
}


//AC
//BOJ 9019 DSLR
//https://www.acmicpc.net/problem/9019
#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, string> cal;
queue<cal> q;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		bool visit[10000] = { false };
		scanf_s("%d %d", &a, &b);
		q.push({ a, "" });
		visit[a] = true;
		while (!q.empty()) {
			cal c = q.front();
			q.pop();
			int x = c.first;
			string s = c.second;

			if (x == b) {
				cout << s << "\n";
				while (!q.empty()) {
					q.pop();
				}
				break; 
			}

			//CASE D
			int temp, temp2;
			if (x != 0) {
				temp = x * 2;
				if (temp > 9999) {
					temp %= 10000;
				}
				if (!visit[temp]) {
					s.push_back('D');
					q.push({ temp, s });
					visit[temp] = true;
					s.pop_back();
				}
			}
			//CASE S
			if(x!=0)	temp = x - 1;
			else if (x == 0)	temp = 9999;
	
			if (!visit[temp]) {
				s.push_back('S');
				q.push({ temp, s });
				visit[temp] = true;
				s.pop_back();
			}
			//CASE L
			if (x != 0) {
				temp = x % 1000;
				temp2 = x / 1000;
				temp *= 10;
				temp += temp2;
				if (!visit[temp]) {
					s.push_back('L');
					q.push({ temp,s });
					visit[temp] = true;
					s.pop_back();
				}
			}
			//CASE R
			if (x != 0) {
				temp = x % 10;
				temp2 = x / 10;
				temp *= 1000;
				temp += temp2;
				if (!visit[temp]) {
					s.push_back('R');
					q.push({ temp,s });
					visit[temp] = true;
					s.pop_back();
				}
			}
		}
	}
	return 0;
}

//AC
//BOJ 1158
//https://www.acmicpc.net/problem/1158
#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	queue<int> q;
	for (int i = 1; i <= N; i++)		
		q.push(i);
	cout << "<";
	while(q.size() > 1){
		for(int i = 1; i<= M; i++){
			if(i != M){
				int a = q.front();
				q.push(a);
				q.pop();
			}
			else{
				cout << q.front() << ", ";
				q.pop();
			}
		}
	}
	cout <<q.front() << ">";
}

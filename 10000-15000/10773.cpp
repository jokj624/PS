//AV
//BOJ 10773 제로 
//https://www.acmicpc.net/problem/10773 
#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int main(){
	int n, num, sum=0;
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d", &num);
		if(num != 0){
			s.push(num);
			sum+=num;
		}	
		else{
			int temp = s.top();
			s.pop();
			sum -= temp;
		}
	}
	cout << sum;
}

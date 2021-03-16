//AC
//BOJ 2493 탑
// https://www.acmicpc.net/problem/2493
#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
stack<int> input;
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		int num;
	    scanf("%d", &num);
		if(s.empty())	{
			input.push(num);
			s.push(i);
			printf("0 ");
		}

		else{
			if(input.top() > num){
				int a = s.top();
				printf("%d ", a);
				s.push(i);
				input.push(num);
			}
			else{
				s.pop();
				input.pop();
				while(!s.empty()){
					if(input.top() > num){
						printf("%d ", s.top());
						s.push(i);
						input.push(num);
						break;
					}
					else{
						s.pop();
						input.pop();
					}
				}
				if(s.empty())	{
					printf("0 ");
					s.push(i);
					input.push(num);
				}
			}
		}
	}
}

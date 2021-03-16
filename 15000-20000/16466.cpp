//AC
//BOJ 16466 콘서트 
//https://www.acmicpc.net/problem/16466 
#include <iostream>
#include <queue>
using namespace std;
priority_queue<int,vector<int>, greater<int> > ticket;
void check_ticket(int n){
	int index = 1;
	while(!ticket.empty()){
		int num = ticket.top();
		if(num != index){
			cout << index;
			return;
		}
		ticket.pop();
		index++;
	}
	cout << index;
}
int main(){
	bool check[1000001]={false};
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int temp;
		scanf("%d", &temp);
		if(check[temp] == false)	{
			ticket.push(temp);
			check[temp] = true;
		}
	}
	check_ticket(n);
	return 0;
}

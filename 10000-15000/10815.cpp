//AC
//BOJ 10815 숫자 카드 
//https://www.acmicpc.net/problem/10815 
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n, m;
	int card[500001];
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d", &card[i]);
	}
	cin >> m;
	sort(card, card+n);
	for(int i=0; i<m; i++){	
		int num;
		scanf("%d", &num);
		if(binary_search(card, card+n, num))	cout << "1" << " ";
		else	cout << "0" << " ";
	}
}

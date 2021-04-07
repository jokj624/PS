//AC
//BOJ 18115 카드 놓기
#include <iostream>
#include <deque>
using namespace std;
deque<int> card;
int order[1010101];
int main(){
	int N, fir;
	int cardNum = 1;
	cin >> N;
	for(int i=1; i<=N; i++){
		scanf("%d", &order[i]);
	}
	for(int i=N; i>=1; i--){
		if(order[i] == 1){
			card.push_front(cardNum);
		}
		else if(order[i] == 2){
			if(card.size() >= 1){
				fir = card.front();
				card.pop_front();
				card.push_front(cardNum);
				card.push_front(fir);
			}
			else{
				card.push_back(cardNum);
			}
		}
		else if(order[i] == 3){
			card.push_back(cardNum);
		}
		cardNum += 1;
	}
	while(!card.empty()){
		printf("%d ", card.front());
		card.pop_front();
	}
	return 0;
}
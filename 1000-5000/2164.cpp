//AC
//BOJ 2164 카드2
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
deque<int> card;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for(int i=1; i<=N; i++) {
        card.push_back(i);
    }
    while(card.size() > 1) {
        card.pop_front();
        int top = card.front();
        card.pop_front();
        card.push_back(top);
    }
    cout << card.back();
    return 0;
}
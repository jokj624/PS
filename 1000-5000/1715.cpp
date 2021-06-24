//AC
//BOJ 1715 카드 정렬하기
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int> > pq;
    int N, card, ans = 0;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &card);
        pq.push(card);
    }
    while(pq.size() > 1){
        int fir = pq.top();
        pq.pop();
        int sec = pq.top();
        pq.pop();
        ans += (fir+sec);
        pq.push(fir+sec);
    }
    printf("%d", ans);
}
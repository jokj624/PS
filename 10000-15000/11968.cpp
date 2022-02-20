//AC
//BOJ 11968 High Card Wins
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> card;
vector<int> elsie;
int visit[101010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int round, num;
    cin >> round;
    for (int i = 0; i < round; i++)
    {
        cin >> num;
        card.push_back(num);
        visit[num] = 1;
    }
    sort(card.begin(), card.end()); // bessie 카드 sorting
    for (int i = 1; i <= round * 2; i++)
    {
        if (!visit[i])
        {
            elsie.push_back(i); // bessie가 가지지 못한 카드를 elsie 에게 넣어준다.
        }
    }
    sort(elsie.begin(), elsie.end()); // elsie 카드 sorting
    int index = 0, point = 0;
    for (int elsie_card : elsie)
    {
        if (index >= round)
            break; // index 예외처리
        if (elsie_card > card[index])
        {
            index++;
            point++; // elsie 카드가 bessie 카드보다 크다면 bessie index를 늘려주고 elsie의 point를 1점 늘려준다.
        }
    }
    cout << point;
    return 0;
}
//AC
//BOJ 11868 님게임 2
#include <iostream>
#include <vector>
using namespace std;
vector<int> stone;
int main(){
	int N, prev;
	cin >> N;
	for(int i=0; i<N; i++){
		int t;
		scanf("%d", &t);
		stone.push_back(t);
	}
	prev = stone[0];
	for(int i=1; i<N; i++){
		prev = prev ^ stone[i];

	}
	if(!prev)	printf("cubelover");
	else	printf("koosaga");
	return 0;
}
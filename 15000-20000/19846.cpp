//AC
//BOJ 19846 신기한 연산
#include <iostream>
#include <vector>
using namespace std;
char ans[101010];
int main(){
    int N, M, Q;
    cin >> N >> M >> Q;
    for(int i=0; i<Q; i++){
        int from, to;
        scanf("%d %d", &from, &to);
    }
    int index = 97, count = 0;
    for(int i=0; i<M; i++){
        if(count == 2) {
            index += 1;
            count = 0;
            if(index >= N+97)  index = 97;
        }
        ans[i] = (char)index;
        count += 1;
    }
    for(int i=0; i<M; i++){
        cout << ans[i];
    }
    return 0;
}
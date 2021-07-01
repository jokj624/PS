//AC
//BOJ 1507 궁금한 민호
#include <iostream>
#include <algorithm>
using namespace std;
int arr[21][21];
int main(){
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                if (i == j)     continue;
                if( k == i || k == j)   continue;
                if(arr[i][j] == -1 || arr[i][k] == -1 || arr[k][j] == -1)   continue;
                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    printf("-1");
                    return 0;
                }
                if(arr[i][j] == (arr[i][k] + arr[k][j])){
                    arr[i][j] = -1;
                }
               
            }
        }
    } 
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= N; j++){
            if(arr[i][j] == -1) continue;
            ans += arr[i][j];
        }
    }
    printf("%d", ans);
    return 0;
}
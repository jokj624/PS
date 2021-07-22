//AC
//BOJ 1486 등산
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1e9+9;
typedef long long ll;
int high[26][26];
ll d[700][700];
ll arr[700];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main(){
    int N, M, T, D;
    ll ans = 0;
    string c;
    cin >> N >> M >> T >> D;
    for(int i=1; i<=N; i++){
        cin >> c;
        for(int j=1; j<=M; j++){
            if(c[j-1] >= 'A' && c[j-1] <= 'Z'){
                high[i][j] = c[j-1] - 'A';
            }
            else if(c[j-1] >= 'a' && c[j-1] <= 'z'){
                high[i][j] = (c[j-1] - 'a') + 26;
            }
            arr[i*M+j] = high[i][j];  
        }
    }
    for(int i= M+1; i<=N*M+M; i++){
        for(int j=M+1; j<=N*M+M; j++){
            if(i!=j)    d[i][j] = INF;
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            for(int k=0; k<4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 1 || ny < 1 || nx > N || ny > M)    continue;
                if(abs(high[nx][ny] - high[i][j]) <= T)   {
                    if(high[nx][ny] <= high[i][j])       d[i*M+j][nx*M+ny] = 1;
                    else if(high[nx][ny] > high[i][j])    d[i*M+j][nx*M+ny] = (high[nx][ny] - high[i][j]) * (high[nx][ny] - high[i][j]);
                }
            }
        }
    }
    for(int k=M+1; k<=N*M+M; k++){
        for(int i=M+1; i <= N*M+M; i++){
            for(int j= M+1; j <= N*M+M; j++){
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    for(int i=M+1; i<=N*M+M; i++){
        if(d[M+1][i] + d[i][M+1] <= D){
            if(ans < arr[i])   ans = arr[i];  
        }
    }
    printf("%lld", ans);
    return 0;
}
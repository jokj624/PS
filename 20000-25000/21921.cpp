#include <iostream>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;
int blog[250001];
ll sum[250001];
int main(){
    int N, X, num;
    cin >> N >> X;
    
    for(int i=0; i<N; i++){
        scanf("%d", &blog[i]);
        if(i==0)  {
            sum[i] = blog[i];
            continue;
        }
        sum[i] = sum[i-1] + blog[i];
    }
    ll maxSum = sum[X-1];
    int cnt = 1;
    for(int i=X; i<N; i++){
        if(maxSum < sum[i] - sum[i-X]){
            maxSum = sum[i]-sum[i-X];
            cnt = 1;
        }
        else if(maxSum == sum[i]-sum[i-X]){
            cnt += 1;
        }
    }
    if(maxSum == 0){
        printf("SAD");
    }
    else{
        printf("%lld\n", maxSum);
        printf("%d", cnt);
    }
}
//AC 
//BOJ 20366 같이 눈사람 만들래?
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
int main(){
    int N, a, min1, min2, ans = 2000000000;
    cin >> N;
    for(int i=0; i<N; i++){
        scanf("%d", &a);
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int l1=0, r1=0;
    for(int i=0; i<N; i++){
        for(int j=i+3; j<N; j++){
            l1 = i+1; r1 = j-1;
            min1 = arr[i]+arr[j];
            while(l1 < r1){
                min2 = arr[l1]+arr[r1];
                int dis = min1-min2;
                ans = min(ans, abs(dis));
                if(dis<0){
                    r1-=1;
                }    
                else if(dis>0){
                    l1+=1;
                }
                else{
                    printf("0");
                    return 0;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}

//AC
//BOJ 20136 멀티탭 스케쥴링2
#include <iostream>
#include <vector>
#include <queue>
#define SIZE 500001
#define INF 987654321
using namespace std;
struct Multi{
    int name; int idx;
};
struct Cmp{
    bool operator()(const Multi &a, const Multi &b){
        return a.idx < b.idx;
    }
};
priority_queue<Multi, vector<Multi>, Cmp> tap;
priority_queue<int, vector<int>, greater<int> > q[SIZE];
int arr[SIZE];
int visit[SIZE];
int main(){
    int N, K, n, ans = 0, cnt = 0;
    cin >> N >> K;
    for(int i=1; i<=K; i++){
        scanf("%d", &n);
        arr[i] = n;
        q[n].push(i);
    }
    for(int i=1; i<=K; i++){
        if(visit[arr[i]]){   // 멀티탭에 꽂혀있음
            q[arr[i]].pop();
            if(!q[arr[i]].empty())  tap.push({arr[i], q[arr[i]].top()});
            else    tap.push({arr[i], INF});
            continue;
        }
        if(cnt < N){   // 멀티탭 자리 남음
            q[arr[i]].pop();
            if(!q[arr[i]].empty())  tap.push({arr[i], q[arr[i]].top()});
            else{
                tap.push({arr[i], INF});
            }
            cnt += 1;
            visit[arr[i]] = 1;
        }
        else{   // 멀티탭 자리 없음
            Multi prev = tap.top();
            visit[prev.name] = 0;
            tap.pop();
            q[arr[i]].pop();
            if(!q[arr[i]].empty())  tap.push({arr[i], q[arr[i]].top()});
            else    tap.push({arr[i], INF});
            visit[arr[i]] = 1;
            ans += 1;
        }
        
    }
    printf("%d", ans);
    return 0;
}
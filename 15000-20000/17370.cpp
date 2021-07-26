//AC
//BOJ 17370 육각형 우리 속의 개미
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int dx[6] = {2, 1, -1, -2, -1, 1};
int dy[6] = {0, 1, 1, 0, -1, -1};
typedef pair<int, int> point;
map<point, int> visit;
int ans, N;
void dfs(int x, int y, int prev, int cnt) {
    if(cnt == 0) {
        if (visit.find({x, y}) != visit.end()){
            ans += 1;
        }
        return;
    }
    if (visit.find({x, y}) != visit.end())  return;
    
    visit[{x, y}] = 1;

    int left = (prev+5) % 6;
    int right = (prev+1) % 6;
    dfs(x + dx[right], y + dy[right], right, cnt - 1);
    dfs(x + dx[left], y + dy[left], left, cnt - 1);
    
    visit.erase({x, y});
}
int main() {
    cin >> N;
    visit[{0, 0}] = 1;
    dfs(2, 0, 0, N);
    cout << ans;
    return 0;
}
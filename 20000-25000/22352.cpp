//AC
//UCPC 2021 B 항체인식
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
using namespace std;
int arr[32][32];
int arr2[32][32];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int visit[32][32];
int N, M;
map<int, int> m;
void bfs(int x, int y, int val, int prev)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = true;
    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = node.first + dx[i];
            int ny = node.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (prev == arr[nx][ny] && !visit[nx][ny])
            {
                arr[nx][ny] = val;
                visit[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ch = 1;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr2[i][j];
            if (arr2[i][j] != arr[i][j])
                ch = 0;
        }
    }
    if (ch)
    { //모두 같음
        cout << "YES";
        return 0;
    }
    int ck = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] != arr2[i][j] && !visit[i][j])
            {
                int prev = arr[i][j];
                arr[i][j] = arr2[i][j];
                bfs(i, j, arr2[i][j], prev);
                ck = 1;
                break; //한번 검사후 종료
            }
        }
        if (ck)
            break;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] != arr2[i][j])
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
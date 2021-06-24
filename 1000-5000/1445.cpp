//AC
//BOJ 1445 일요일 아침의 데이트
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 999999999
using namespace std;
struct point
{
    int x;
    int y;
    int cost;
    int gcost;
};
struct cmp
{
    bool operator()(const point &a, const point &b)
    {
        if (a.cost == b.cost)
        {
            return a.gcost > b.gcost;
        }
        return a.cost > b.cost;
    }
};
char graph[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
priority_queue<point, vector<point>, cmp> pq;
int main()
{
    int N, M;
    int sx, sy, ex, ey;
    cin >> N >> M;
    int d[51][51];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];
            d[i][j] = INF;
            if (graph[i][j] == 'S')
            {
                d[i][j] = 0;
                sx = i;
                sy = j;
            }
            else if (graph[i][j] == 'F')
            {
                ex = i;
                ey = j;
            }
        }
    }
    pq.push({sx, sy, 0, 0});
    int ans1 = 0, ans2 = 0, ansTrue = 0;
    while (!pq.empty())
    {
        if (ansTrue)
            break;
        int cx = pq.top().x;
        int cy = pq.top().y;
        int cg = pq.top().cost;
        int nextcg = pq.top().gcost;
        pq.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int gnum = cg;
            int nextg = nextcg;
            if (nx == ex && ny == ey)
            {
                ans1 = gnum;
                ans2 = nextg;
                ansTrue = 1;
                break;
            }
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (d[nx][ny] != INF)
                continue;
            if (graph[nx][ny] == 'g')
            {
                pq.push({nx, ny, gnum + 1, nextg});
            }

            else if (graph[nx][ny] == '.')
            {
                int ck = 0;
                for (int j = 0; j < 4; j++)
                {
                    int nnx = nx + dx[j];
                    int nny = ny + dy[j];
                    if (nnx < 0 || nny < 0 || nnx >= N || nny >= M)
                        continue;
                    if (graph[nnx][nny] == 'g')
                    {
                        pq.push({nx, ny, gnum, nextg + 1});
                        ck = 1;
                        break;
                    }
                }
                if (!ck)
                    pq.push({nx, ny, gnum, nextg});
            }
            d[nx][ny] = d[cx][cy] + 1;
        }
    }
    printf("%d %d", ans1, ans2);
}

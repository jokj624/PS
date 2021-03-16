//AC
//BOJ 20046 Road Reconstruction
//https://www.acmicpc.net/problem/20046
//ACM-ICPC 예선 K번
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#define INF 1000000000
using namespace std;
int graph[1001][1001];
int d[1001][1001];
int c[1001][1001];
int dx[4] = { 1,0,-1, 0 };
int dy[4] = { 0,1, 0, -1 };
typedef tuple<int, int, int> pq_dist;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &graph[i][j]);
			d[i][j] = INF;
		}
	}
	if (graph[1][1] == -1) {
		cout << -1;
		return 0;
	}
	priority_queue<pq_dist, vector<pq_dist>, greater<pq_dist> > pq;
	queue<pair<int, int> > q;
	d[1][1] = graph[1][1];
	pq.push(make_tuple(d[1][1], 1, 1));
	while (!pq.empty()) {
		int x = get<1>(pq.top());
		int y = get<2>(pq.top());
		pq.pop();

		if (!c[x][y]) {
			c[x][y] = 1;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx > n || ny > m || nx < 1 || ny < 1)	continue;
				if (graph[nx][ny] == -1)	continue;
				if (d[nx][ny] > d[x][y] + graph[nx][ny]) {
					d[nx][ny] = d[x][y] + graph[nx][ny];
					pq.push(make_tuple(d[nx][ny], nx, ny));
				}
			}
		}
	}

	if (d[n][m] == INF)	cout << -1;
	else	cout << d[n][m];
	return 0;
} 

//AC
//BOJ 19542 전단지 돌리기
//https://www.acmicpc.net/problem/19542 
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> node[100001];
int a[100001];
bool visit[100001];
int n, s, d;
int dfs(int x) {
   int depth=0;
   bool leaf = true;
   visit[x] = true;
   for (int i = 0; i < node[x].size(); i++) {
      int y = node[x][i];
      if (!visit[y]) {
         leaf = false;
         depth = max(depth, dfs(y) + 1);
      }
   }
   if (!leaf)
      a[x] = depth;
   return a[x];
}
int main() {
   scanf("%d %d %d", &n, &s, &d);
   for (int i = 1; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      node[x].push_back(y);
      node[y].push_back(x);
   }
   for (int i = 1; i <= n; i++)
      visit[i] = false;
   dfs(s);
   

   int ans = 0;
   queue<int> q;
   q.push(s);
   for (int i = 1; i <= n; i++)
      visit[i] = false;
   visit[s] = true;
   if (a[s] > d) {
      while (!q.empty()) {
         int x = q.front();
         q.pop();
         for (int i = 0; i < node[x].size(); i++) {
            int y = node[x][i];
            if (!visit[y] && a[y] >= d) {
               q.push(y);
               visit[y] = true;
               ans++;
            }
         }
      }
   }
   printf("%d\n", ans * 2);
}

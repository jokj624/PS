//AC
//BOJ 17451 평행 우주
//https://www.acmicpc.net/problem/17451 
#include <cstdio>
#include <algorithm>
using namespace std;
int n, fast = 0;
long long ans, v[300001];

int main() {
   scanf("%d", &n);
   for (int i = 0; i < n; i++) {
      scanf("%lld", &v[i]);
      fast = (v[fast] > v[i]) ? fast : i;
   }
   ans = v[fast];
   for (int i = fast-1; i >= 0; i--) {
      long long q = ans / v[i];
      if (ans % v[i] != 0)
         q++;
      ans = (ans > v[i] * q) ? ans : v[i] * q;
   }
   printf("%lld", ans);
}




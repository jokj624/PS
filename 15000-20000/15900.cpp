//AC
//BOJ 15900 나무 탈출 
// https://www.acmicpc.net/problem/15900
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> tree[500001];
bool visit[500001]={false};
int d[500001];
int main()
{
   	int n, a, b, cnt=0;
   	scanf("%d", &n);
   	for(int i=0; i<n-1; i++){
        scanf("%d %d", &a, &b);
        tree[b].push_back(a);
        tree[a].push_back(b);
   	}
	queue<int> q;
	q.push(1);
	visit[1]=true;
	d[1] = 0;
    while(!q.empty()){
    	int x = q.front();
    	q.pop();
    	for(int i=0; i<tree[x].size(); i++){
    		int y = tree[x][i];
    		if(!visit[y]){
    			q.push(y);
    			visit[y] = true;
    			d[y] = d[x]+1;
    			if(tree[y].size()==1)	cnt+=d[y];
			}
		}
	}
    if(cnt%2)   printf("Yes");
    else    printf("No");
   return 0;
}
 

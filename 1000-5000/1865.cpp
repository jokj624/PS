//AC
//BOJ 1865 웜홀 
//https://www.acmicpc.net/problem/1865 
#include <iostream>
#include <vector>
#include <string.h>
#include <utility>
#include <queue>
#define INF 99999999
using namespace std;
long long int d[501];
bool c[501]={false};
long long int cnt[501] ={0};
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		vector<pair<int, int> > graph[501];
		bool negative_cycle = false;
		memset(c, false, sizeof(c));
		int n, m, w;
		scanf("%d %d %d", &n, &m, &w);
		for(int i=0; i<m; i++){
			int s, e, t;
			scanf("%d %d %d",&s, &e, &t);
			graph[s].push_back(make_pair(e,t));
			graph[e].push_back(make_pair(s,t));
		}
		for(int i=0; i<w; i++){
			int s,e,t;
			scanf("%d %d %d",&s, &e, &t);
			graph[s].push_back(make_pair(e,-t));
		}
		for(int i=2; i<=n; i++){
			d[i] = INF;
		}
		queue<int> q;
		for(int j=1; j<=n; j++){
		    memset(cnt, 0, sizeof(cnt));
		    if(c[j]==true || negative_cycle==true)  continue;
		    d[j]=0;
		    c[j]=true;
		    q.push(j);
		    cnt[j]++;
		    while(!q.empty()) {
    		    int from = q.front();
		        q.pop();
		        c[from] = false;
		        if(negative_cycle)	continue;
		    
		        for(auto &e : graph[from]){
			        int to = e.first;
			        int cost = e.second;
			        if(d[to]>d[from]+cost){
				        d[to]=d[from]+cost;
				        if(c[to]==false){
					        q.push(to);
					        c[to] = true;
					        cnt[to]++;
					        if(cnt[to]>=n){
					    	    negative_cycle = true;
					        }
				        }   
			        }
		        }
		    }
		  
	    }
	    if(!negative_cycle)	printf("NO\n");
		else	printf("YES\n");
    }
}


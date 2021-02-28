//次短路模板题

#include <stdio.h>
#include <queue>
#include <iostream>
#include <string.h>
using namespace std;
#define MAXN 100005

int m,n,cnt;
int dis1[MAXN],dis2[MAXN],vis[MAXN],head[MAXN*2];

queue <int>que;

struct node{
	int to,next,w;
}map[MAXN*2];

void add(int u,int v,int w){
	map[++cnt] = (node){v,head[u],w};
	head[u] = cnt;
}
void SPFA(int u,int *dis){
	memset(vis,0,sizeof(vis));
	que.push(u);
	dis[u] = 0;
	vis[u] = 1;
	while(!que.empty()){
		int u = que.front(); que.pop();
		vis[u] = 0;
		for(int k=head[u];k;k=map[k].next){
			int v = map[k].to;
			int w = map[k].w+dis[u];
			if( dis[v] > w){
				dis[v] = w;
				if(!vis[v]){
					vis[v] = 1;
					que.push(v);
				}
			}
		}
	}
}
int main(void){
    memset(dis1,0x3f,sizeof(dis1));
    memset(dis2,0x3f,sizeof(dis2));
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);	add(v,u,w);
	}
	SPFA(1,dis1); SPFA(n,dis2);
	int ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		for(int k=head[i];k;k=map[k].next){
			int v = map[k].to;
			int w = dis1[i]+dis2[v]+map[k].w;
			if(dis1[n]<w && ans>w)	ans = w;
			//不能用 dis1[n]<dis1[i]+dis2[i] 来进行判断
			//∵此时会忽略掉自环
			//相当于取了自环中最短的边进行尝试，不行则放弃这个点
		}
	}
	cout << ans << endl;
	return 0;
}

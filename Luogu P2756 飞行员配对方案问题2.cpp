#include <queue>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define MAXN 10005
#define INF 0x3f3f3f3f

int n, m;
int vis[MAXN], dep[MAXN], temp[MAXN], match[MAXN];
int head[MAXN], cnt = 1;

struct node{
    int to, w, next;
}map[MAXN * 2];

void add(int u, int v, int w)
{
    map[++cnt] = (node){v, w, head[u]};
    head[u] = cnt;
}

bool bfs()
{
    memset(dep, -1, sizeof dep);
    memcpy(temp, head, sizeof head);
    {
        
    }
    queue <int>que;
    que.push(0);
    dep[0] = 0;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (int k=head[u];k;k=map[k].next)
        {
            int v = map[k].to;
            int w = map[k].w;
            if (w && dep[v] == -1)
            {
                dep[v] = dep[u] + 1;
                que.push(v);
            }
        }
    }
    return dep[m+1] != -1;
}
 
int dfs(int u, int flow)
{
    if (u == m + 1) return flow;
    int rmnd = flow;
    for (int k=temp[u];k;k=map[k].next)
    {
        temp[u] = k;
        int v = map[k].to;
        int w = map[k].w;
        if (w && dep[v] == dep[u] + 1)
        {
            int delta = dfs(v, min(w, rmnd));
            rmnd -= delta;
            map[k].w -= delta;
            map[k ^ 1].w += delta;
            if (!map[k].w) match[u] = v;
            if (!rmnd) break;
        }
    }
    return flow - rmnd;
}

int Dinic()
{
    int ans = 0;
    while (bfs())
    {
        ans += dfs(0, INF);
    }
    return ans;
}

int main(void)
{
    cin >> n >> m;
    int u, v;
    cin >> u >> v;
    while (u!=-1 && v!=-1)
    {
        add(u, v, 1);
        add(v, u, 0);
        cin >> u >> v;
    }
    for (int i=1;i<=n;i++)
    {
        add(0, i, 1);
        add(i, 0, 0);
    }
    for (int i=n+1;i<=m;i++)
    {
        add(i, m+1, 1);
        add(m+1, i, 0);
    }
    cout << Dinic() << endl;
    for (int i=1;i<=n;i++)
    {
        if (match[i])
        {
            cout << i << " " << match[i] << endl;
        }
    }
    return 0;
}
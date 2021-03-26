#include <queue>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define MAXN 10005
#define INF 0x3f3f3f3f

int m, n, s = 0, t = 201, cost;
int cnt = 1;
int head[MAXN], dis[MAXN], vis[MAXN], val[MAXN];

struct node{
    int to, w, w2, next, f, f2;
    void init()
    {
        w = w2;
        f = f2;
    }
}map[MAXN*2];

void add(int u, int v, int w, int f)
{
    map[++cnt] = (node){v, w, w, head[u], f, f};
    head[u] = cnt;
}

bool bfs(int q)
{
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    queue <int> que;
    que.push(s);
    dis[s] = 0;
    vis[s] = 1;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        vis[u] = 0;
        for (int k=head[u];k;k=map[k].next)
        {
            int v = map[k].to;
            int w = map[k].w;
            int f = map[k].f * q;
            if (w && dis[u] + f < dis[v])
            {
                dis[v] = f + dis[u];
                if (!vis[v])
                {
                    vis[v] = 1;
                    que.push(v);
                }
            }
        }
    }
    return dis[t] != INF;
}

int dfs(int u, int flow, int q)
{
    if (u == t)
    {
        return flow;
    }
    int rmnd = flow;
    vis[u] = 1;
    for (int k=head[u];k && rmnd;k=map[k].next)
    {
        int v = map[k].to;
        int w = map[k].w;
        int f = map[k].f * q;
        if (w && dis[v] == dis[u] + f && !vis[v])
        {
            int delta = dfs(v, min(rmnd, w), q);
            //cout << u << " " << v << " " << w << endl;
            rmnd -= delta;
            map[k].w -= delta;
            map[k ^ 1].w += delta;
            cost += delta * f * q;
        }
    }
    vis[u] = 0;
    return flow - rmnd;
}

void Dinic(int k)
{
    cost = 0;
    while (bfs(k))
    {
        //for (int i=1;i<=n;i++) cout << i << " " << dis[i+100] << endl;
        memset(vis, 0, sizeof vis);
        dfs(s, INF, k);
    }
}

int main(void)
{
    cin >> m >> n;
    for (int i=1;i<=m;i++)
    {
        cin >> val[i];
        add(s, i, val[i], 0);
        add(i, s, 0, 0);
    }
    for (int j=1;j<=n;j++)
    {
        cin >> val[j+100];
        add(j+100, t, val[j+100], 0);
        add(t, j+100, 0, 0);
    }
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            int f;
            cin >> f;
            add(i, j+100, INF, f);
            add(j+100, i, 0, -f);
        }
    }
    Dinic(1);
    cout << cost << endl;
    for (int i=1;i<=cnt;i++)
    {
        map[i].init();
    }
    Dinic(-1);
    cout << cost;
    return 0;
}
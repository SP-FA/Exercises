#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>
using namespace std;
#define MAXN 200005
#define t n+K+1
#define INF 0x3f3f3f3f

int K, n, m, cnt = 1, s = 0;
int dep[MAXN], temp[MAXN * 2], head[MAXN * 2], vis[MAXN];

struct node{
    int to, next, w;
}map[MAXN*2];

void add(int u, int v, int w)
{
    map[++cnt] = (node){v, head[u], w};
    head[u] = cnt;
}

bool bfs(void)
{
    memset(dep, -1, sizeof dep);
    memcpy(temp, head, sizeof head);
    queue <int> que;
    que.push(s);
    dep[s] = 0;
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
    return dep[t] != -1;
}

int dfs(int u, int flow)
{
    if (u == t)
    {
        return flow;
    }
    int rmnd = flow;
    for (int k = temp[u];k && rmnd;k=map[k].next)
    {
        int v = map[k].to;
        int w = map[k].w;
        temp[u] = k;
        if (w && dep[v] == dep[u] + 1)
        {
            int delta = dfs(v, min(rmnd, w));
            rmnd -= delta;
            map[k].w -= delta;
            map[k ^ 1].w += delta;
        }
    }
    return flow - rmnd;
}

int Dinic(void)
{
    int ans = 0;
    while (bfs())
    {
        ans += dfs(s, INF);
    }
    return ans;
}

void print(int u)
{
    for (int k=head[u];k;k=map[k].next)
    {
        int v = map[k].to;
        int w = map[k].w;
        if (v == t) continue;
        if (w == 1 && !vis[v])
        {
            cout << v << " ";
            vis[v] = 1;
        }
    }
}

int main(void)
{
    cin >> K >> n;
    for (int i=1;i<=K;i++)
    {
        int knum;
        cin >> knum;
        m += knum;
        add(i+n, t, knum);
        add(t, i+n, 0);
    }
    for (int i=1;i<=n;i++)
    {
        int num;
        cin >> num;
        for (int j=1;j<=num;j++)
        {
            int ki;
            cin >> ki;
            add(i, ki+n, 1);
            add(ki+n, i, 0);
        }
        add(s, i, 1);
        add(i, s, 0);
    }
    if (Dinic() != m)
    {
        cout << "No Solution!";
        return 0;
    }
    for (int i=1;i<=K;i++)
    {
        cout << i << ": ";
        print(i + n);
        cout << endl;
    }
    return 0;
}
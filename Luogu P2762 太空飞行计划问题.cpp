#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
#define MAXN 2500
#define INF 0x3f3f3f3f

int n, m, tot;
int cnt = 1;
int s = 0, t = 101;
int vis[MAXN], head[MAXN], dep[MAXN], temp[MAXN], dis[MAXN];

struct node{
    int to, w, next;
}map[MAXN];

void add(int u, int v, int w)
{
    map[++cnt] = (node){v, w, head[u]};
    head[u] = cnt;
}

bool bfs(void)
{
    memset(dep, -1, sizeof dep);
    memset(dis, -1, sizeof dis);
    queue <int>que;
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
                dis[v] = 1;
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
    int rmnd  = flow;
    temp[u] = head[u];
    for (int k=temp[u];k && rmnd;k=map[k].next)
    {
        temp[u] = k;
        int v = map[k].to;
        int w = map[k].w;
        if (w && dep[v] == dep[u] + 1)
        {
            int delta = dfs(v, min(rmnd, w));
            //cout << u << " " << v << " " << w << endl;
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

void read(void)
{
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        int sponsor;
        cin >> sponsor;
        tot += sponsor;
        add(s, i+50, sponsor);
        add(i+50, s, 0);
        char tools[10000];
        memset(tools,0,sizeof tools);
        cin.getline(tools,10000);
        int ulen=0, tool;
        while (sscanf(tools + ulen,"%d",&tool) == 1)//之前已经用scanf读完了赞助商同意支付该实验的费用
        {//tool是该实验所需仪器的其中一个      
            //这一行，你可以将读进来的编号进行储存、处理，如连边。
            add(i+50, tool, INF);
            add(tool, i+50, 0);
            if (tool==0)
            {
                ulen++;
            }
            else
            {
                while (tool)
                {
                    tool/=10;
                    ulen++;
                }
            }
            ulen++;
        }
    }
    for (int i=1;i<=m;i++)
    {
        int pay;
        cin >> pay;
        add(i, t, pay);
        add(t, i, 0);
    }
}

int main(void)
{
    read();
    int ans =  Dinic();
    for (int i=1;i<=n;i++)
    {
        if (dep[i+50] != -1)
        {
            cout << i << " ";
        }
    }
    cout << endl;
    for (int j=1;j<=m;j++)
    {
        if (dis[j] != -1)
        {
            cout << j << " ";
        }
    }
    cout << endl << tot - ans;
    return 0;
}
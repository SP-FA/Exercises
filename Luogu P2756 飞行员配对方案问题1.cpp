#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define MAXN 10005

int n, m, ans;
int vis[MAXN];
int match[MAXN];
int head[MAXN], cnt;

struct node{
    int to, next;
}map[MAXN * 2];

void add(int u, int v)
{
    map[++cnt] = (node){v, head[u]};
    head[u] = cnt;
}

bool Hungary(int u)
{
    for (int k=head[u];k;k=map[k].next)
    {
        int v = map[k].to;
        if (!vis[v])
        {
            vis[v] = 1;
            if (!match[v] || Hungary(match[v]))
            {
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int main(void)
{
    cin >> n >> m;
    int u, v;
    cin >> u >> v;
    while(u!=-1 && v!=-1)
    {
        add(u, v);
        cin >> u >> v;
    }
    for (int i=1;i<=n;i++)
    {
        memset(vis, 0, sizeof vis);
        ans += Hungary(i);
    }
    cout << ans << endl;
    for (int i=n+1;i<=m;i++)
    {
        if (match[i])
            cout << match[i] << " " << i << endl;
    }
    return 0;
}
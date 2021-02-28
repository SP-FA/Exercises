#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 5005

int n,ans,minn;
bool vis[MAXN];

struct node{
    int L,W;
}stick[MAXN];

bool cmp(node a,node b)
{
    if(a.L == b.L)
    {
        return a.W > b.W;
    }
    return a.L > b.L;
}

int main()
{
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> stick[i].L >> stick[i].W;
    }
    sort(stick + 1, stick + n + 1, cmp);
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            minn = stick[i].W;
            for (int j=i+1;j<=n;j++)
            {
                if (stick[j].W <= minn && !vis[j])
                {
                    vis[j] = 1;
                    minn = stick[j].W;
                }
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}

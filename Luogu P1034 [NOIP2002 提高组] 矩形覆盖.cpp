#include <queue>
#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXN 505
#define INF 0x3f3f3f3f

int n, k, ans=INF;
int visx[MAXN], visy[MAXN];
int vis[MAXN][MAXN];
int map[MAXN][MAXN];

void dfs(int num, int area)
{
    if (num == k)
    {
        for (int i=1;i<=n;i++)
        {
            int X = visx[i];
            int Y = visy[i];
            if (!map[X][Y]) return;
        }
        ans = min(ans, area);
        return;
    }
    for (int i1=1;i1<=n;i1++)
    for (int j1=1;j1<=n;j1++)
    {
        int X1 = visx[i1];
        int Y1 = visy[j1];
        if (!vis[X1][Y1])
        {
            for (int i2=1;i2<=n;i2++)
            for (int j2=1;j2<=n;j2++)
            {
                int X2 = visx[i2];
                int Y2 = visy[j2];
                if (!vis[X2][Y2])
                {
                    int temp = abs(X1-X2) * abs(Y1-Y2);
                    if (temp + area > ans) continue;
                    for (int i=min(X1, X2);i<=max(X1, X2);i++)
                    {
                        vis[i][Y1]++;
                        vis[i][Y2]++;
                    }
                    for (int i=min(Y1, Y2)+1;i<max(Y1, Y2);i++)
                    {
                        vis[X1][i]++;
                        vis[X2][i]++;
                    }
                    for (int i=min(X1, X2);i<=max(X1, X2);i++)
                    for (int j=min(Y1, Y2);j<=max(Y1, Y2);j++)
                        map[i][j]++;
                    dfs(num+1, temp+area);
                    for (int i=min(X1, X2);i<=max(X1, X2);i++)
                    {
                        vis[i][Y1]--;
                        vis[i][Y2]--;
                    }
                    for (int i=min(Y1, Y2)+1;i<max(Y1, Y2);i++)
                    {
                        vis[X1][i]--;
                        vis[X2][i]--;
                    }
                    for (int i=min(X1, X2);i<=max(X1, X2);i++)
                    for (int j=min(Y1, Y2);j<=max(Y1, Y2);j++)
                        map[i][j]--;
                }
            }
        }
    }
}

int main(void)
{
    cin >> n >> k;
    for (int i=1;i<=n;i++)
    {
        int xi, yi;
        cin >> xi >> yi;
        visx[i] = xi;
        visy[i] = yi;
    }
    dfs(0, 0);
    cout << ans;
    return 0;
}
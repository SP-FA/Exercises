#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXN 505
#define INF 0x3f3f3f3f

int n, k, ans = INF;

struct node
{
    int x, y;
}point[MAXN];

struct Node
{
    int X1 = 0, X2 = INF;
    int Y1 = 0, Y2 = INF;
    int cnt = 0;
    int calculate_area()
    {
        if (!cnt) return 0;
        return (X1 - X2) * (Y1 - Y2);
    }
    void push(node a)
    {
        X1 = max(X1, a.x);
        X2 = min(X2, a.x);
        Y1 = max(Y1, a.y);
        Y2 = min(Y2, a.y);
        cnt = 1;
    }
    bool inrec(Node a)
    {
        return (a.X1>=X1 && a.X2<=X1 && a.Y1>=Y1 && a.Y2<=Y1) ||
               (a.X1>=X2 && a.X2<=X2 && a.Y1>=Y1 && a.Y2<=Y1) ||
               (a.X1>=X1 && a.X2<=X1 && a.Y1>=Y2 && a.Y2<=Y2) ||
               (a.X1>=X2 && a.X2<=X2 && a.Y1>=Y2 && a.Y2<=Y2);
    }
}rectangle[5];

bool check()
{
    for (int i=1;i<=k;i++)
    {
        for (int j=i+1;j<=k;j++)
        {
            if (rectangle[i].inrec(rectangle[j])) return 0;
        }
    }
    return 1;
}

void dfs(int num, int area)
{
    if (ans <= area) return;
    if (num > n)
    {
        if (check())
            ans = area;
        return;
    }
    for (int i=1;i<=k;i++)
    {
        Node temp = rectangle[i];
        rectangle[i].push(point[num]);
        dfs(num + 1, area - temp.calculate_area() + rectangle[i].calculate_area());
        rectangle[i] = temp;
    }
}

int main(void)
{
    cin >> n >> k;
    for (int i=1;i<=n;i++)
    {
         cin >> point[i].x >> point[i].y;
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}
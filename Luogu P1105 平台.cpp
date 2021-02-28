#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXN 20202

int n;
int Left[MAXN], Right[MAXN];
//int vis[MAXN];

struct {
    int H, L, R;
}bar[MAXN];

void work(int id)
{
    for (int i=1;i<=n;i++)
    {
        //if (vis[i]) continue;
        if (i == id) continue;
        if (bar[i].H >= bar[id].H) continue;
        if (bar[id].L > bar[i].L && bar[id].L < bar[i].R)
        {
            if (bar[i].H > bar[Left[id]].H) Left[id] = i;
        }
        if (bar[id].R > bar[i].L && bar[id].R < bar[i].R)
        {
            if (bar[i].H > bar[Right[id]].H) Right[id] = i;
        }
    }
}

int main(void)
{
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> bar[i].H >> bar[i].L >> bar[i].R;
    }
    for (int i=1;i<=n;i++)
    {
        work(i);
    }
    for (int i=1;i<=n;i++)
    {
        cout << Left[i] << " " << Right[i] << endl;
    }
    return 0;
}
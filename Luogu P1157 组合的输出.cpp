#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXN 25

int n, r, tot;
int ans[MAXN];

void dfs()
{
    if (tot >= r)
    {
        for (int i=1;i<=r;i++)
        {
            if (ans[i] < 10)
                cout << "  " << ans[i];
            else
                cout << " " << ans[i];
        }
        cout << endl;
        return;
    }
    for (int i=ans[tot]+1;i<=n;i++)
    {
        ans[++tot] = i;
        dfs();
        tot--;
    }
}

int main(void)
{
    cin >> n >> r;
    dfs();
    return 0;
}
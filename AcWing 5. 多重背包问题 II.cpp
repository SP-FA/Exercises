#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXN 25000

int n, v, cnt;
int val[MAXN], wight[MAXN], f[MAXN];

int main(void)
{
    cin >> n >> v;
    for (int i=1;i<=n;i++)
    {
        int w, vlu, m;
        cin >> w >> vlu >> m;
        for (int k=1;k<m;k*=2)
        {
            m -= k;
            wight[++cnt] = k * w;
            val[cnt] = k * vlu;
        }
        if (m > 0)
        {
            wight[++cnt] = m * w;
            val[cnt] = m * vlu;
        }
    }
    for (int i=1;i<=cnt;i++)
    {
        for (int j=v;j>=wight[i];j--)
        {
            f[j] = max(f[j], f[j-wight[i]]+val[i]);
        }
    }
    cout << f[v];
}
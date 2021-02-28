#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXN 1005

int n, v;
int val[MAXN], wight[MAXN], f[MAXN];

int main(void)
{
    cin >> n >> v;
    for (int i=1;i<=n;i++)
    {
        cin >> wight[i] >> val[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=wight[i];j<=v;j++)
        {
            f[j] = max(f[j], f[j-wight[i]]+val[i]);
        }
    }
    cout << f[v];
    return 0;
}
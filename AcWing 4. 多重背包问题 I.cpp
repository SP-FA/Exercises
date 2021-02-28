#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXN 105

int n, v;
int val[MAXN], wight[MAXN], num[MAXN], f[MAXN];

int main(void)
{
    cin >> n >> v;
    for (int i=1;i<=n;i++)
    {
        cin >> wight[i] >> val[i] >> num[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=v;j>=wight[i];j--)
        {
            for (int k=1;k<=num[i] && j>=k*wight[i];k++)
            {
                f[j] = max(f[j], f[j-k*wight[i]] + k*val[i]);
            }
        }
    }
    cout << f[v];
    return 0;
}
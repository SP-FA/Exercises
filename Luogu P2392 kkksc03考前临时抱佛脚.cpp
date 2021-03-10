#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int num[5],sum[5];
int bag[5][25];
int f[1205], ans;

void dp(int k)
{
    for (int i=1;i<=num[k];i++)
    {
        for (int j=sum[k]/2;j>=bag[k][i];j--)
        {
            f[j] = max(f[j], f[j-bag[k][i]]+bag[k][i]);
        }
    }
}

int main(void)
{
    for (int i=1;i<=4;i++)
    {
        cin >> num[i];
    }
    for (int i=1;i<=4;i++)
    {
        for (int j=1;j<=num[i];j++)
        {
            cin >> bag[i][j];
            sum[i] += bag[i][j];
        }
    }
    for (int i=1;i<=4;i++)
    {
        memset(f, 0, sizeof f);
        dp(i);
        ans += sum[i] - f[sum[i]/2];
        //cout << sum[i] - f[sum[i]/2] << " ";
    }
    cout << ans;
    return 0;
}
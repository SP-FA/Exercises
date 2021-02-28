#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXN 1005

int n, m;
int bag[MAXN];
int val[MAXN], wight[MAXN];

int main(void)
{
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> wight[i] >> val[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=m;j>=wight[i];j--)
        {
            bag[j] = max(bag[j], bag[j-wight[i]] + val[i]);
        }
    }
    cout << bag[m] << endl;
    return 0;
}
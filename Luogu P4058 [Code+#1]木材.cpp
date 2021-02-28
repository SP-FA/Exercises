#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXN 200005
#define INF S

typedef unsigned long long ull;

ull n, S, L, tot, Left, Right = INF;
ull H[MAXN], A[MAXN];

ull Dichotomy(void)
{
    while (Left <= Right)
    {
        tot = 0;
        ull mid = (Left + Right) >> 1;
        for (ull i=1;i<=n;i++)
        {
            ull len = H[i] + mid * A[i];
            if (len >= L) tot += len;
            if (tot >= S) break;
        }
        if (tot >= S) Right = mid - 1;
        else          Left  = mid + 1;
    }
    return Left;
}

int main(void)
{
    cin >> n >> S >> L;
    for (ull i=1;i<=n;i++) cin >> H[i];
    for (ull i=1;i<=n;i++) cin >> A[i];
    for (int i=1;i<=n;i++)
    {
        if (H[i] >= L)
        {
            tot += H[i];
        }
    }
    if (tot >= S) cout << 0;
    else cout << Dichotomy();
    return 0;
}
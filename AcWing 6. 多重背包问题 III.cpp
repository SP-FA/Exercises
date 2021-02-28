#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXN 20005

int n, V;
int wight[MAXN], val[MAXN], num[MAXN], f[MAXN];

struct{
    int pos,value;
}que[MAXN];

int main(void)
{
    cin >> n >> V;
    for (int i=1;i<=n;i++)
    {
        cin >> wight[i] >> val[i] >> num[i];
        num[i] = min(num[i], V/wight[i]);
        for (int j=0;j<wight[i];j++)
        {
            int head = 0;
            int rear = -1;
            for (int k=0;k<=(V-j)/wight[i];k++)
            {
                int x = f[k * wight[i] + j] - k * val[i];
                while (head <= rear && que[head].pos < k - num[i])
                {
                    head++;
                }
                while (head <= rear && que[rear].value <= x)
                {
                    rear--;
                }
                que[++rear].pos = k;
                que[rear].value = x;
                f[k * wight[i] + j] = que[head].value + k * val[i];
            }
        }
    }
    cout << f[V];
    return 0;
}
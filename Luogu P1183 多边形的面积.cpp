#include <stdio.h>
#include <iostream>
using namespace std;

int n,S;
int x[500],y[500];

int main(void)
{
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> x[i] >> y[i];
	x[n+1] = x[1];
	y[n+1] = y[1];
	for(int i=1;i<=n;i++)
		S += x[i]*y[i+1]-x[i+1]*y[i];
	cout << S/2;
	return 0;
}

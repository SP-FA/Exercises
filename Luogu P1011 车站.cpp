#include <stdio.h>
#include <iostream>
using namespace std;


int main(void){
	int a,n,m,t;
	int num1[21]={0,1,1,2,2};
	int num2[21]={0,0,0,0,1};
	cin >> a >> n >> m >> t;
	for(int i=5;i<n;i++)
	{
		num1[i] = num1[i-1]+num1[i-2]-1;
		num2[i] = num2[i-1]+num2[i-2]+1;
	}
	int b = (m-num1[n-1]*a)/num2[n-1];
	int ans = num1[t]*a+num2[t]*b;
	cout << ans;
	return 0;
}

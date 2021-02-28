#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define MAXN 1000001

int T,n,sol;
int a[MAXN],num1[MAXN],num2[MAXN],ri[MAXN],le[MAXN];

int Lowbit(int x) {return x & -x;}

void add1(int x, int w){
	for(;x<=n;x+=Lowbit(x)) num1[x] += w;
}

int query1(int x){
	int ans=0;
	for(;x>0;x-=Lowbit(x)) ans += num1[x];
	return ans;
}

void add2(int x, int w){
	for(;x<=n;x+=Lowbit(x)) num2[x] += w;
}

int query2(int x){
	int ans=0;
	for(;x>0;x-=Lowbit(x)) ans += num2[x];
	return ans;
}

int main(void)
{
	cin >> T;
	while(T--){
		n=0,sol=0;
		memset(a   ,0,MAXN);
		memset(num1,0,MAXN);
		memset(num2,0,MAXN);
		memset(ri  ,0,MAXN);
		memset(le  ,0,MAXN);
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		for(int i=1;i<=n;i++){
			le[i] += query1(a[i]-1);
			add1(a[i],1);
		}
		for(int i=n;i>=1;i--){
			ri[i] += query2(n)-query2(a[i]);
			add2(a[i],1);
		}
		for(int i=1;i<=n;i++){
			sol += ri[i]*le[i];
		}
		cout << sol << endl;
	}
	return 0;
}
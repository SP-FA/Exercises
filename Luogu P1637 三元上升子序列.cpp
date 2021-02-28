#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 300000

long long n,sol;
int num[MAXN],num2[MAXN],ti[MAXN],ri[MAXN],le[MAXN];
long long b[MAXN],a[MAXN];

long long Lowbit(int x) {return x & -x;}

void add(int x, int w){
	for(;x<=n;x+=Lowbit(x)) num[x] += w;
}

long long query(int x){
	long long ans=0;
	for(;x>0;x-=Lowbit(x)) ans += num[x];
	return ans;
}

int main(void)
{
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i] = a[i];
	}
	/**************离散化**************/
	sort(b+1,b+n+1);
	int len = unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)
		a[i] = lower_bound(b+1,b+1+len,a[i])-b;
	/**********************************/
	for(int i=1;i<=n;i++){
		le[i] += query(a[i]-1);
		add(a[i],1);
	}
	memset(num,0,MAXN);
	for(int i=n;i>=1;i--){
		ri[i] += query(n)-query(a[i]);
		add(a[i],1);
	}
	for(int i=1;i<=n;i++){
		sol += ri[i]*le[i];
	}
	cout << sol << endl;
	return 0;
}
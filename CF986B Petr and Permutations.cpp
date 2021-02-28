#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXN 1000001

int n,ans2;
int a[MAXN],num[MAXN];

int Lowbit(int x) {return x & -x;}

void add(int x, int w){
	for(;x<=n;x+=Lowbit(x)) num[x] += w;
}

int query(int x){
	int ans=0;
	for(;x>0;x-=Lowbit(x)) ans += num[x];
	return ans;
}

int main(void)
{
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		ans2 += query(n)-query(a[i]);
		add(a[i],1);
	}
	if((3*n+ans2)%2) cout << "Um_nik";
	else cout << "Petr";
	return 0;
}
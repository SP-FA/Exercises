//普通做法，取交集。
//也可以用动态开点线段树

#include <stdio.h>
#include <iostream>
using namespace std;

struct node{
	long long l,r,w;
}query[1005];

int main(void){
	long long n,m,cnt=0;
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		long long flag,x,y,w,ans=0;
		cin >> flag;
		if(flag == 1){
			cin >> x >> y >> w;
			query[++cnt].l = x;
			query[  cnt].r = y;
			query[  cnt].w = w;
		}
		else{
			cin >> x >> y;
			for(int j=1;j<=cnt;j++){
				if(query[j].l>y || query[j].r<x) continue; //取交集
				ans += (min(query[j].r,y)-max(query[j].l,x)+1)*query[j].w;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
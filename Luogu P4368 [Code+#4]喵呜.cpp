#include <stdio.h>
#include <iostream>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f

long long T,n,h,x,y,a,b,ans;

long long step(long long x, long long y){
	if(x%a!=0 || y%b!=0) return INF;
	if((x/a-y/b)%2 == 0) return max(x/a,y/b);
	return INF;
}
int main(void){
	cin >> T;
	for(int i=1;i<=T;i++){
		ans = INF;
		cin >> n >> h >> x >> y >> a >> b;
		ans = min(ans,step(x-1,y-1));
		ans = min(ans,step(n-x,y-1));
		ans = min(ans,step(x-1,h-y));
		ans = min(ans,step(n-x,h-y));
		if(ans == INF)	cout << "-1" << endl;
		else			cout << ans  << endl;
	}
	return 0;
}
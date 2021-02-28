#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

long long ans,tot,cnt,Q[100];
string n;

int main(void){
	cin >> n;
	for(int i=0;i<n.size();i++){
		if(n[i]=='A' || n[i]=='Q') tot++;
		if(n[i]=='A') Q[++cnt] = tot-cnt;
	}
	for(int i=1;i<=cnt;i++)
		ans += Q[i]*(tot-cnt-Q[i]);
	cout << ans << endl;
	return 0;
}

#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
#define MAXN 1000000

struct node{
	int num,toMoscow;
	string name;
}city[200];

int sum,p,ans=MAXN,n=1;

int main(void){
	while(cin >> city[n].num >> city[n].toMoscow >> city[n].name)
		n++;
	for(int i=1;i<=n;i++){
		sum = 0;
		for(int j=1;j<=n;j++)
			sum += city[j].num*abs(city[i].toMoscow-city[j].toMoscow);
		if(sum <= ans){
			ans = sum;
			p = i;
		}
	}
	cout << city[p].name << " " << ans;
	return 0;
}
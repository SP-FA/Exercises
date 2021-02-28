#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

bool tenet;
int n,step;
int num1[1000005],num2[1000005],sum[1000005];
string m;

int main(){
	cin >> n >> m;
	int l = m.length();
	for(int i=0;i<l;i++){
		num1[i+1] = m[i]-'0';
		num2[l-i] = m[i]-'0';
		if(n==16 && num1[i+1]>10){
			num1[i+1] = num1[i+1]-7;
			num2[l-i] = num2[l-i]-7;
		}
	}
	while(1)
	{
		for(int i=1;i<=l;i++){
			sum[i] += num1[i]+num2[i];
			if(sum[i]>=n){
				sum[i+1]++;
				sum[i] = sum[i]-n;
				if(i == l) l++;
			}
		}
		tenet = true;
		for(int i=1;i<=(l/2);i++){
			if(sum[i] != sum[l-i+1]){
				tenet = false;
				break;
			}
		}
		if(tenet){
			cout << "STEP=" << step+1;
			return 0;
		}
		else{
			step++;
			for(int i=1;i<=l;i++){
				num1[i] = sum[i];
				num2[l-i+1] = sum[i];
				sum[i] = 0;
			}
		}
		if(step > 30){
			cout << "Impossible!";
			return 0;
		}
	}
	return 0;
}
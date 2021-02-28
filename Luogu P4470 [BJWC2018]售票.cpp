#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define ASC s[i]-'A'

int n,tot;
int trie[10005][26],num[105];
char s[105],a[26]={     'A','B','C','D','E',
			'F','G','H','I','J','K','L','M',
			'N','O','P','Q','R','S','T','U',
			'V','W','X','Y','Z'};

void insert(void){
	int u=0;
	for(int i=0;s[i];i++){
		if(!trie[u][ASC])
			trie[u][ASC] = ++tot;
		u = trie[u][ASC];
	}
	return;
}
void search(void){
	int u=0;
	for(int i=0;s[i];i++){
		if(!trie[u][ASC]) return;
		u = trie[u][ASC];
	}
	for(int i=0;i<=25;i++)
		if(trie[u][i]) num[i]++;
}

int main(void){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> s;
		insert();
		memset(s,0,sizeof(s));
	}
	cin >> s;
	search();
	cout << "***";
	for(int i=0;i<=25;i++){
		if(!num[i]) cout << '*';
		else cout << a[i];
		if(i==4 || i==12 || i==20) cout << endl;
	}
	cout << "***" << endl;
	return 0;
}
#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1100000], cf[1100000];
int n, l, num = 0;
int main() {
	//freopen("5.in", " r ", stdin);
	//freopen("5.out", " w ", stdout);
	cin >> l >> n;
	for (int i = 0; i <= l; i++)
	{
		a[i] = 1;
	}
	while (n--)
	{
		int q; int z;
		cin >> q >> z;
		cf[q]--;
		cf[z + 1]++;
	}
 
	for (int i = 1; i <= l; i++)
	{
		cf[i] = cf[i - 1] + cf[i];
	}
	for (int i = 1; i <= l; i++)
	{
		a[i] += cf[i];
		if (a[i] == 1)num++;
	}
	cout << num;
}
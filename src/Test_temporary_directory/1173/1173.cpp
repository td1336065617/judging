#include<bits/stdc++.h>
using namespace std;
long long int n, m, t[500][500], sj[500],T,num,R,Q;
long long int mod1= 1610612741;
string str;
long long int f[1000000],p[1000000];
long long int sc[100000];
void floy(int k) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			t[i][j] = min(t[i][k] + t[k][j], t[i][j]);
		}
	}
}
string s,s1;
int main() {
 
	cin >> n >> m>>T>>R>>Q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			t[i][j] = 1e17;
		}
	}
	for (int i = 0; i < n; i++)
		t[i][i] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> sj[i];
	}

	cin >> s;
	p[0] = 1;
	for (int i = 1; i <= s.length(); i++)
	{
		f[i] = (f[i - 1] * 131 + (s[i - 1] - 'a' + 1)) % mod1;
		p[i] = (p[i - 1] * 131) % mod1;
	}
	for (int i = 0; i < T; i++)
	{
		long long int f1=0;
		cin >>s1;
		for (int j = 1; j <= s1.length(); j++)
		{
			f1 = (f1 * 131 + (s1[j - 1] - 'a' + 1)) % mod1;
		}
		for (int j = s1.length(); j <= s.length(); j++)
		{
			int r1 = j, l1 = j - s1.length();
			int r2 = s1.length(), l2 = 0;
			long long int qz = ((f[r1] - f[l1] * p[r1 - l1]) % mod1 + mod1) % mod1;
			long long int qzq = (f1 % mod1 + mod1) % mod1;
			if (qz == qzq)
			{
				sc[i]++;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		long long int qd, zd, qz;
		cin >> qd >> zd >> qz;
		t[qd][zd] = t[zd][qd] = min(qz,t[zd][qd]);
	}
	long long int up = 0;
	for (int i = 0; i < Q; i++)
	{
		long long int qd, zd, tz;
		cin >> qd >> zd >> tz;
		while (sj[up] <= tz && up < n) {
			floy(up);
			up++;
		}
		if (sj[qd] <= tz && sj[zd] <= tz)
		{
			if (t[qd][zd] == 1e17)num-=T;
			else
			{
				if (num > 0 && num + sc[t[qd][zd] % T] < 0)
					return -1;
				num+=sc[t[qd][zd]%T];
				
			}
		}
		else
		{
			num -= T;
		}
	}
	if (num>R)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	cout <<num;
}
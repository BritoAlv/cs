#include <bits/stdc++.h>

#define fori(a,b) for (int i = a; i <= b; i++)
#define forj(a,b) for (int j = a; j <= b; j++)
#define forn  for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	forn
	{
		if(i + 1 < n && s[i] == s[i+1]) {
			cout << s[i] << s[i] << endl;
			return;
		}
	}
	forn{
		if(i >= 2) {
			set<char> qq;
			forj(i-2, i) qq.insert(s[j]);
			if(qq.size() == 3) {
				forj(i-2, i) cout << s[j];
				cout << endl;
				return;
			}
		}
	}
	cout << -1 << endl;
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--) solve();	
}
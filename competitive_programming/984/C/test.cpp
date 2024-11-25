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

int check(const int pos, const string &s) {
	const vector<char> vals = {'1', '1', '0', '0'};
	fori(pos, pos + 3) {
		if(i >= s.size() || s[i] != vals[i - pos]) {
			return 0;
		}
	}
	return 1;
}


void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	vector<int> w(n - 3);
	fori(0, n - 4) w[i] = check(i, s);
	set<int> FF;
	fori (0, n - 4) if (w[i]) FF.insert(i);
	int q;
	cin >> q;
	while(q--) {
		int a;
		char b;
		cin >> a >> b;
		a--;
		s[a] = b;
		fori(max(0, a-5), min(n-4, a+5)) {
			if (FF.find({i}) != FF.end()) {
				FF.erase(i);
			}
			int val = check(i, s);
			if(val) {
				FF.insert(i);
			}
		}
		cout << (FF.size() > 0 ? "YES" : "NO") << endl;
	}
}


int main()
{
	int t = 1;
	cin >> t;
	while(t--) solve();	
}

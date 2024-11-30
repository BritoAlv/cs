#include <bits/stdc++.h>

#define doo(a) for(int i_i = 0; i_i < a; i_i++)
#define fori(a,b) for (int i = a; i <= b; i++)
#define forj(a,b) for (int j = a; j <= b; j++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	string t;
	cin >> s >> t;
	int flag = 0;
	fori(0, n-1) {
		flag |= s[i] == '1';
		if (s[i] != t[i] && !flag) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
}

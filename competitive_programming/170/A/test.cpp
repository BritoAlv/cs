#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

vector<int> z_function(string s) {
	int n = s.size();
	vector<int> z(n);
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i < r) {
			z[i] = min(r - i, z[i - l]);
		}
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}
		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}
	return z;
}

void solve() {
	string s, t;
	cin >> s >> t;
	string q = s + "#" + t;
	string p = t + "#" + s;
	auto z1 = z_function(q);
	auto z2 = z_function(p);
	int lp = 0;
	lp = max(lp, z1[s.size() + 1]);
	lp = max(lp, z2[t.size() + 1]);
	if (lp == 0) {
		cout << t.size() + s.size() << endl;
	} else {
		cout << t.size() + s.size() - lp + 1 << endl;
	}
}


int main() {
	int t;
	cin >> t;
	while (t--) solve();
}

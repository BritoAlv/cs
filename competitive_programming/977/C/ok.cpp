#include <bits/stdc++.h>

#define doo(a) for(int i_i = 0; i_i < a; i_i++)
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

int ss(vi &a, vi &b) {
	int n = a.size();
	int m = b.size();
	int a_index = 0;
	int b_index = 0;
	set<int> seenA;
	while (b_index < m) {
		if ( (a_index >= n || a[a_index] != b[b_index]) && seenA.find(b[b_index]) == seenA.end()) {
			return 0;
		}
		if (a_index < n && a[a_index] == b[b_index]) {
			seenA.insert(a[a_index]);
			a_index++;
		}
		b_index++;
	}
	return 1;
}

void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	vi a(n);
	vi b(m);
	forn cin >> a[i];
	fori(0, m-1) cin >> b[i];
	cout << ss(a, b) << endl;
	while (q--) {
		int ind, val;
		cin >> ind >> val;
		b[--ind] = val;
		cout << ss(a, b) << endl;
	}
	cout << endl;
}

int main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
}
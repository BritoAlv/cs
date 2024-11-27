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
	int ans = 1;
	int n = a.size();
	int m = b.size();
	vi posA(n);
	vi condition(n, 1);
	forn posA[a[i]] = i;
	map<int, set<int> > pos;
	vi unique(n);
	fori(0, m-1) {
		if (pos.find(b[i]) == pos.end())
			unique[b[i]] = pos.size();
		pos[b[i]].insert(i);
	}
	for (const auto &z: pos) {
		const int first_pos = *z.second.begin();
		condition[z.first] = first_pos  >= posA[z.first] + (first_pos - unique[z.first]);
	}
	forn ans &= condition[i];
	return ans;
}

void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	vi a(n);
	vi b(m);
	forn {
		cin >> a[i];
		a[i]--;
	}
	fori(0, m-1) { cin >> b[i], b[i]--; }
	cout << (ss(a, b) ? "YA" : "TIDAK") << endl;
	while (q--) {
		int ind, val;
		cin >> ind >> val;
		ind--, val--;
		b[ind] = val;
		cout << (ss(a, b) ? "YA" : "TIDAK") << endl;
	}
}

int main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
}
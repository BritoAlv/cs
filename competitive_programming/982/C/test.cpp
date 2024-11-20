#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		forn cin >> a[i];
		map<ll, vector<int> > st;
		forn {
			ll exp = a[i] + (i + 1) - 1;
			st[exp].push_back(i);
		}
		ll best = n;
		set<pair<int, ll> > start;
		for (auto z: st[n]) {
			start.insert({z, n});
		}
		st[n].clear();
		while (start.size()) {
			const auto next = start.begin();
			start.erase(next);
			ll current = next->second + next->first;
			best = max(best, current);
			for (auto z: st[current]) {
				start.insert({z, current});
			}
			st[current].clear();
		}
		cout << best << endl;
	}
}

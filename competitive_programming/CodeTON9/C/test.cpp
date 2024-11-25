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

void solve() {
	ll x, m;
	cin >> x >> m;
	ll ans = 0;
	for(ll y = 1; y <= min(2 * x + 5, m); y++) {
		ll xorr = x ^ y;
		if(xorr > 0 && x != y)
			ans += (x % xorr == 0 || y % xorr == 0);
	}
	cout << ans << endl;
}

int main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
}

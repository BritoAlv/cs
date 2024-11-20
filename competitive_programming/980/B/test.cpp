#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	forn cin >> a[i];
	sort(a.begin(), a.end());
	ll ans = 0;
	int offset = 0;
	forn{
		a[i] -= offset;
		ll apport = min(k - ans, (n - i) * a[i]);
		ans += apport;
		if(ans == k) {
			ans += i;
			break;
		}
		offset += a[i];
	}
	cout << ans << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--) solve();
}
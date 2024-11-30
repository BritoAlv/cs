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
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n);
	fori(0, n-1) {
		cin >> a[i];
		if (i > 0) a[i] += a[i - 1];
	};
	vector<ll> dp(n, 0);
	for (int l = n - 1; l >= 0; l--) {
		ll app = 0;
		int low = l;
		int up = n - 1;
		if (a[up] - (l > 0 ? a[l - 1] : 0) <= x) {
			app += up - l + 1;
		} else {
			while (up - low > 1) {
				int midd = low + (up - low) / 2;
				if (a[midd] - (l > 0 ? a[l - 1] : 0) > x) {
					up = midd;
				} else {
					low = midd + 1;
				}
			}
			while (up - 1 >= l && a[up-1] - (l > 0 ? a[l - 1] : 0) > x) {
				up--;
			}
			app += (up - l);
			if (up < n-1) app += dp[up + 1];
		}
		dp[l] = app;
	}
	ll ans = 0;
	fori(0, n-1) {
		//cout << dp[i] << wp;
		ans += dp[i];
	}
	//cout << endl;
	cout << ans << endl;
}

int main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
}
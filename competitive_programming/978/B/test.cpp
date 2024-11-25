#include <bits/stdc++.h>

#define do(x) for(int i_i = 0; i_i < x; i_i++)
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
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n);
	forn cin >> a[i];
	sort(a.begin(), a.end(), greater<ll>());
	ll ans = a[0];
	ll sum_smallest = 0;
	ll sum_greatest = 0;
	fori(0, min(x-1, n-1)) sum_greatest += a[i];
	fori(x, n-1) sum_smallest += a[i];
	ll pending = a[0] * x - sum_greatest;
	if(pending < sum_smallest) {
		ans += (sum_smallest - pending) / x;
		ans += (sum_smallest - pending) % x != 0;
	}
	cout << ans << endl;
}

int main() {
	int t = 1;
	//cin >> t;
	while (t--) solve();
}
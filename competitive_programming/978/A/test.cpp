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

const int maxn = 200010;
ll a[maxn];

void solve() {
	int n, r;
	cin >> n >> r;
	int ans = 0;
	int odds = 0;
	forn cin >> a[i];
	forn odds += a[i] % 2;
	forn {
		r -= a[i] / 2;
		ans += 2 * (a[i] / 2);
	}
	if(odds <= r) cout << ans + odds << endl;
	else cout << ans + (r - (odds - r)) << endl;
}

int main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
}

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
	vector<ll> a(n);
	ll sum = 0;
	fori(0, n-1) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % n != 0) {
		cout << "NO" << endl;
		return;
	}
	ll exp = sum / n;
	fori(1, n-2) {
		ll cur = a[i - 1];
		if (cur < exp) {
			a[i + 1] -= exp - cur;
			a[i - 1] = exp;
		} else if (cur > exp) {
			a[i + 1] += cur - exp;
			a[i - 1] = exp;
		}
	}
	fori(0, n-1) {
		if (a[i] != exp) {
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
#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

int w(ll k, stack<ll> a) {
	int oppor = 1;
	while(a.size()) {
		ll top = a.top();
		a.pop();
		if(a.size() == 0) {
			return oppor;
		}
		ll next = a.top();
		a.pop();
		ll dif = next - top;
		if(dif <= k) {
		}
		else {
			if(!oppor) {
				return 0;
			}
			a.push(next);
			oppor = 0;
		}
	}
	return 1;
}

void solve() {
	int n;
	cin >> n;
	stack<ll> a;
	vector<ll> b(n);
	forn
	{
		cin >> b[i];
	}
	reverse(b.begin(), b.end());
	forn a.push(b[i]);
	ll l = 0;
	ll g = 1e18;
	while(g - l > 1) {
		ll middle = l + (g -l)/2;
		if(w(middle, a)) {
			g = middle;
		}
		else {
			l = middle + 1;
		}
	}
	while(g - 1 >= 1 &&  w(g - 1, a)) {
		g--;
	}
	cout << g << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}

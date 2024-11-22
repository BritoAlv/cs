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

void ans(int x) {
	if (x) cout << "YES" << endl;
	else cout << "NO" << endl;
}

void solve() {
	int n;
	cin >> n;
	forn {
		char x;
		cin >> x;
		a[i] = x == '1';
	}
	int fl = a[0] == 1 || a[n - 1] == 1;
	for (int i = 1; i < n; i++) {
		fl |= a[i] && a[i - 1];
	}
	ans(fl);
}


int main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
}

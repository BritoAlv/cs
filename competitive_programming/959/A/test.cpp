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
	int n, m;
	cin >> n >> m;
	vector<vi > a(n, vi(m));
	fori(0, n-1)
		forj(0, m-1) cin >> a[i][j];
	if (m == n && m == 1) {
		cout << -1 << endl;
		return;
	}
	int pt = 1;
	fori(0, n - 1) {
		forj(0, m-1) {
			int x = pt / m;
			int y = pt % m;
			pt += 1;
			pt %= n * m;
			cout << a[x][y] << wp;
		}
		cout << endl;
	}
}

int main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
}

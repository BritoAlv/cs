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
	string a, b, c;
	cin >> a >> b >> c;
	vector<vi > dp(a.size() + 1, vi(b.size() + 1, 0));
	// dp[i][j] the minimum cant of chars that could have been changed in c
	// to remove the first i chars of a, and the first j chars of b.
	// implicitly this means that already deleted the first i + j chars of c.
	fori(1, a.size()) {
		dp[i][0] = dp[i - 1][0] + (a[i - 1] != c[i - 1]);
	}
	fori(1, b.size()) {
		dp[0][i] = dp[0][i - 1] + (b[i - 1] != c[i - 1]);
	}
	fori(1, a.size()) {
		forj(1, b.size()) {
			dp[i][j] = dp[i - 1][j] + (c[i + j - 1] != a[i - 1]);
			dp[i][j] = min(dp[i][j], dp[i][j-1] + (c[i + j - 1] != b[j - 1]));
		}
	}
	cout << dp[a.size()][b.size()] << endl;
}

int main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
}

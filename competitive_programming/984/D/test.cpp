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
	int n, m;
	cin >> n >> m;
	int a[n][m];
	int ans = 0;
	fori(0, n-1) {
		forj(0, m-1) {
			char x;
			cin >> x;
			a[i][j] = x - '0';
		}
	}
	queue<char> moves;
	vector<vector<int> > values;
	pi cp = {0, -1};
	while (n - 2 >= 0 && m - 2 >= 0) {
		moves.push('R');
		fori(1, m - 1) {
			moves.push('R');
		}
		fori(1, n - 1) {
			moves.push('D');
		}
		fori(1, m - 1) {
			moves.push('L');
		}
		fori(1, n - 2) {
			moves.push('U');
		}
		m -= 2;
		n -= 2;

		vector<int> one;
		while (!moves.empty()) {
			const auto top = moves.front();
			moves.pop();
			switch (top) {
				case 'R':
					cp.second++;
					break;
				case 'L':
					cp.second--;
					break;
				case 'D':
					cp.first++;
					break;
				case 'U':
					cp.first--;
					break;
				default:
					continue;
			}
			one.push_back(a[cp.first][cp.second]);
		}
		values.push_back(one);
	}

	const vector<int> expected = {1, 5, 4, 3};
	for(auto z : values) {
		fori(0, z.size()-1) {
			vector<int> got;
			forj(i, i + 3) {
				got.push_back(z[j % z.size()]);
			}
			ans += expected == got;
		}
	}
	cout << ans << endl;
}

int main() {
	int t = 1;
	cin  >> t;
	while (t--) solve();
}

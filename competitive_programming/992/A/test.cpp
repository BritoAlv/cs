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
	int n, k;
	cin >> n >> k;
	vi a(n);
	vector<vi > arr(k, vi());
	fori(0, n-1) {
		cin >> a[i];
		arr[a[i] % k].push_back(i);
	}
	fori(0, k-1) {
		if (arr[i].size() == 1) {
			cout << "YES" << endl;
			cout << arr[i][0] + 1 << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
}

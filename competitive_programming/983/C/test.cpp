#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vi a(n);
		forn {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		set<pair<int, int> > X;
		forn {
			X.insert({a[i], i});
		}
		X.insert({2e9, n});
		int ans = n;
		for (int j = 1; j < n; j++) {
			int sum = 0;
			sum += j - 1;
			sum += n - X.lower_bound({a[j-1] + a[j], -1})->second;
			ans = min(sum, ans);
		}
		cout << ans << endl;
	}
}
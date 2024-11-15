#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

int ceil(int a, int b) {
	return a / b + (a % b) != 0;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		constexpr int n = 3;
		vector<int> values(n);
		forn {
			cin >> values[i];
		}
		sort(values.begin(), values.end());
		ll ans = 0;

		auto do_op = [&values, &ans](int i, int j, int cant) {
			values[i] -= cant;
			values[j] -= 2 * cant;
			ans += cant;
			sort(values.begin(), values.end());
		};
		int minn = min(values[1] - values[0], (values[2] - values[1]));
		minn = min(minn, values[2] / 2);
		do_op(1, 2, minn);
		if (values[2] - values[1] <= 1) {
			int minn = (values[1] - values[0]) / 3;
			values[1] -= 3 * minn;
			values[2] -= 3 * minn;
			ans += 2 * minn;
			sort(values.begin(), values.end());
		} else if (values[1] - values[0] <= 1) {
			int minn = min(values[0], (values[2] - values[1]) / 3);
			values[0] -= minn;
			values[1] -= minn;
			values[2] -= 4 * minn;
			ans += 2 * minn;
			sort(values.begin(), values.end());
		}
		while (values[2] - values[0] > 1 && values[1] > 0) {
			do_op(1, 2, 1);
		}
		ans += values[0];
		cout << ans << endl;
	}
}

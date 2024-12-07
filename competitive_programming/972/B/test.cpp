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

int ceil(const int a, const int b) {
	return a / b + (a % b > 0);
}

int ds(const int a, const int b) {
	int dif1 = abs(b - a);
	return max(0, (dif1 - 2) / 2);
}

void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	set<int> teachers;
	fori(0, m-1) {
		int x;
		cin >> x;
		teachers.insert(x);
	}
	while (q--) {
		int x;
		cin >> x;
		auto pt1 = teachers.lower_bound(x);
		if (pt1 == teachers.end()) {
			// all the teachers are behind David.
			const auto closest_teacher = *(--pt1);
			cout << n - closest_teacher << endl;
		} else if (pt1 == teachers.begin()) {
			// all the teachers are to its right.
			const auto closest_teacher = *(pt1);
			cout << closest_teacher - 1 << endl;
		} else {
			const int one = (*pt1);
			const int two = *(--pt1);
			const int midpoint = min(one, two) + abs(two - one)/2;
			int minn = ds(x, two) + ceil(abs(one - x), 2); // this option is nice.
			minn = max(minn, ds(x, one) + ceil( abs(two - x) ,2));
			minn = max(minn, min(abs(one - x), abs(two - x))); // stay in place.
			minn = max(minn, min(abs(one - midpoint), abs(two - midpoint)));
			cout << minn << endl;
		}
	}
}

int main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
}
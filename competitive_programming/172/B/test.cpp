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

int ceil(int a, int b) {
	return a / b + (a % b > 0);
}

void solve() {
	int n;
	cin >> n;
	map<int, int> A;
	fori(0, n-1) {
		int x;
		cin >> x;
		A[x]++;
	}
	int ones = 0;
	for (auto z : A) {
		ones += z.second  == 1;
	}
	int ans = 2 * ceil(ones, 2) + (A.size() - ones);
	cout << ans << endl;
}

int main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
}

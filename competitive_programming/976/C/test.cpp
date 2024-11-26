#include <bits/stdc++.h>

#define doo(a) for(int i_i = 0; i_i < a; i_i++)
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

map<vi, int> A = {
	{{0, 0, 0}, 0},
	{{0, 0, 1}, -1},
	{{0, 1, 0}, 1},
	{{0, 1, 1}, 1},
	{{1, 0, 0}, 1},
	{{1, 0, 1}, 0},
	{{1, 1, 0}, -1},
	{{1, 1, 1}, 0}
};

vi binary(ll x) {
	vi result(61, 0);
	for (int i = 0; i < 61; i++) {
		result[i] = x % 2;
		x /= 2;
	}
	return result;
}

void solve() {
	ll b, c, d;
	cin >> b >> c >> d;
	const vector<int> dd = binary(d); // 1110
	vector<int> cc = binary(c);		  // 0010
	vector<int> bb = binary(b);       // 1010
	                                  //  100
	int n = dd.size();
	ll a = 0;
	for(int i = n-1; i >= 0; i--){
		vector<int> scenario = {dd[i], cc[i], bb[i]};
		//cout << dd[i] << wp << cc[i] << wp << bb[i] << endl;
		if (A[scenario] == -1) {
			cout << -1 << endl;
			return;
		}
		a *= 2;
		a += A[scenario];
	}
	cout << a << endl;
}

int main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
}
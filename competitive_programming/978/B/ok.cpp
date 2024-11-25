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
	int n, x;
	cin >> n >> x;
	ll ans = 0;
	set<pi, greater<pi>> A;
	forn {
		int x;
		cin >> x;
		A.insert({x, i});
	}
	while(A.size() > x) {
		ans++;
		vector<pi> top;
		fori(0, x-1) {
			top.pb(*A.begin());
			A.erase(A.begin());
		}
		for(auto z : top) {
			z.first -=1;
			if(z.first > 0) {
				A.insert(z);
			}
		}
	}
	cout << ans + A.begin()->first << endl;
}

int main() {
	int t = 1;
	while (t--) solve();
}

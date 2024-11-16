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
		int n, k;
		cin >> n >> k;
		vi a(n);
		if(n == 1 || (n == 2 && k == 1)) {
			cout << 1 << endl << 1 << endl;
		}
		else if(k == n || k == 1) {
			cout << -1 << endl;
		}
		else {
			cout << 3 << endl;
			if(k % 2) {
				cout << 1 << wp << k-1 << wp << k+2 << endl;
			}
			else {
				cout << 1 << wp << k << wp << k+1 << endl;
			}
		}
	}
}
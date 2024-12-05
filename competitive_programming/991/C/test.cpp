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
	string s;
	cin >> s;
	int n = s.size();
	vi a(n);
	fori(0, n-1) {
		char x = s[i];
		a[i] = (int) (x - '0');
	}
	int sum = 0;
	int two = 0;
	int tree = 0;
	fori(0, n-1) {
		if (a[i] == 2) two ++;
		else if (a[i] == 3) tree++;
		else sum += a[i];
	}
	int exp = (9 - (sum % 9)) % 9 ;
	fori(0, min(100, two)) {
		forj(0, min(100, tree)) {
			int four = i;
			int twoo = two - four;
			int treee = tree - j;
			if ( (4 * four + 2 * twoo + 3 * treee) % 9 == exp) {
				cout << "YES" << endl;
				return;
			}
		}
	}
	cout << "NO" << endl;
}

int main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
}

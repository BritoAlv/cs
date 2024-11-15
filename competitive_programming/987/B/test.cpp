#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vi p(n);
		vi pp(n);
		forn {
			cin >> p[i];
			pp[i] = i + 1;
		}
		for (int i = 0; i < 1; i++) {
			for (int j = 1; j < n; j++)
				if (abs(p[j] - p[j - 1]) == 1 && p[j] < p[j - 1]) {
					swap(p[j], p[j - 1]);
				}
		}
		cout << (pp == p ? "YES" : "NO") << endl;
	}
}
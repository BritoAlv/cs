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

void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	vi a(n);
	fori(0, n-1) {
		char x = s[i];
		a[i] = (int) (x - '0');
	}
	fori(0, n-1) {
		// the largest number at po
		vector<pi> candidates;
		forj(i, min(n-1, i + 8)) {
			candidates.push_back({ a[j] - (j - i) , -j});
		}
		sort(candidates.begin(), candidates.end());
		pi selected = candidates.back();
		for (int j = -selected.second; j >= i+1; j--) {
			swap(a[j], a[j-1]);
		}
		a[i] = selected.first;
	}
	forj(0, n-1) {
		cout << a[j];
	}
	cout << endl;
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--) solve();	
}

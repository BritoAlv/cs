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

int mex(vector<int> const &A)
{
	set<int> b(A.begin(), A.end());

	int result = 0;
	while (b.count(result))
		++result;
	return result;
}

void solve()
{
	int n, x;
	cin >> n >> x;
	vi a(n);
	forn cin >> a[i];
	int mexx = mex(a);
	map<int, set<pi>> freq;
	forn freq[a[i] % x].insert({a[i], i});
	for (int i = 0; i < mexx; i++) {
		freq[i % x].erase(freq[i % x].begin());
	}
	while (!freq[mexx % x].empty() && freq[mexx % x].begin()->first <= mexx) {
			freq[mexx % x].erase(freq[mexx % x].begin());
			mexx++;
	}
	cout << mexx << endl;
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--) solve();	
}

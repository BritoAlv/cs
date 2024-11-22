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

const int maxn = 200010;
ll a[maxn];

void solve()
{
	int n;
	cin >> n;
	forn cin >> a[i];
	ll score = 0;
	if(n == 1) {
		cout << 0 << endl;
	}
	else {
		sort(a, a + n);
		ll minn = a[0];
		ll maxx = a[n-1];
		cout << (n - 1) * (maxx - minn)  << endl;
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--) solve();	
}
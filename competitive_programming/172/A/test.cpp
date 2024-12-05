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
	int n, k;
	cin >> n >> k;
	vi a(n);
	fori(0, n-1) cin >> a[i];
	sort(a.begin(), a.end());
	ll sum = 0;
	for (int i = n-1; i >= 0; i--) {
		sum += a[i];
		if (sum > k) {
			cout << (k - (sum - a[i]) ) << endl;
			return;
		}
		if (sum == k) {
			cout << 0 << endl;
			return;
		}
	}
	cout << k  - sum << endl;
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--) solve();	
}

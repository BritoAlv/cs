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

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<ll> cost(k + 1);
	fori(0, k-1) {
		ll a, b;
		cin >> a >> b;
		cost[a] += b;
	}
	sort(cost.begin(), cost.end(), greater<ll>());
	ll sum = 0;
	fori(0, min(n-1, k-1)) {
		sum += cost[i];
	}
	cout << sum << endl;

}

int main()
{
	int t = 1;
	cin >> t;
	while(t--) solve();	
}

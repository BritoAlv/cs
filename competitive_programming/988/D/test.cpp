#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

void solve() {
	int n, m;
	ll L;
	cin >> n >> m >> L;
	queue<pair<int, int>> intervals;
	forn
	{
		int a, b;
		cin >> a >> b;
		intervals.push({a, b});
	}
	queue<pair<int, int>> power_ups;
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		power_ups.push({a, b});
	}
	int ans = 0;
	ll c_power = 1;
	set<pair<int, int>, greater<pair<int, int>>> avav;
	int pt = 0;
	while(intervals.size() > 0) {
		int l = intervals.front().first;
		int r = intervals.front().second;
		intervals.pop();
		while(power_ups.size() > 0 && power_ups.front().first < l) {
			avav.insert({power_ups.front().second, pt++});
			power_ups.pop();
		}
		int power_required = r - l + 2;
		while(power_required > c_power) {
			if(avav.size() == 0) {
				cout << -1 << endl;
				return;
			}
			c_power += avav.begin()->first;
			avav.erase(avav.begin());
			ans++;
		}
	}
	cout << ans << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}    
}

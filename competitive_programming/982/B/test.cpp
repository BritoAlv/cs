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
	int n;
	cin >> n;
	vector<int> a(n);
	forn cin >> a[i];
	int ans  =n-1;
	forn
	{
		int to_delete = i;
		for(int j = i+1; j < n; j++) {
			if(a[j] > a[i]) to_delete++;
		}
		ans = min(ans, to_delete);
	}
	cout << ans << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--) solve();
}
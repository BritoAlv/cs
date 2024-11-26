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

void solve()
{
	int n, k;
	cin >> n >> k;
	if(k == 1) {
		cout << n << endl;
		return;
	}
	int ans = 0;
	while(n > 0) {
		ans += n % k;
		n /= k;
	}
	cout << ans << endl;
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--) solve();	
}
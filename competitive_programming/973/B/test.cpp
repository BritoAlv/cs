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
	int n;
	cin >> n;
	vi a(n);
	fori(0, n-1) cin >> a[i];
	if (n >= 3) {
		ll sum1 = 0;
		fori(0, n -3) sum1 += a[i];
		cout << a[n-1] - (a[n-2] - sum1) << endl;
	} else {
		cout << a[n-1] - a[n-2] << endl;
	}
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--) solve();	
}

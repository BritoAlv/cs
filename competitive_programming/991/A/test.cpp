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
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	fori(0, n-1) cin >> a[i];
	int sum = 0;
	fori(0, n-1) {
		sum += a[i].size();
		if (sum > m) {
			cout << i << endl;
			return;
		}
	}
	cout << n << endl;
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--) solve();	
}

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
	for(int i = 0; i < n; i++) {
		cout << 2 * i + 1 << wp;
	}
	cout << endl;
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--) solve();	
}

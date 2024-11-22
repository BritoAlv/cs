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
	/*
	 * f(t) non empty subsequences that only contain 0,
	 * g(t) non empty subsequences that contain at least one 1.
	 * dado t, hallar un string binario tal que |f(t) - g(t)| sea minimo.
	*/
	int n;
	cin >> n;
	fori(0, n-2) cout << 0;
	cout << 1 << endl;
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--) solve();	
}

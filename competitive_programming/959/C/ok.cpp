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
	int n, x;
	cin >> n >> x;
	vi a(n);
	fori(0, n-1) cin >> a[i];
	for (int l = 0; l < n; l++) {
		for (int r = l; r < n; r++) {
			int tox_level = 0;
			fori(l, r) {
				tox_level += a[i];
				if (tox_level > x) tox_level = 0;
			}
			printf("For values %d, %d tox level = %d\n", l, r, tox_level);
		}
	}
}

int main()
{
	int t = 1;
	while(t--) solve();	
}
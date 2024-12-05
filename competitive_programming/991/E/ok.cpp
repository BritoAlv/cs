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
	string a, b, c;
	cin >> a >> b >> c;
	int n = c.size();
	int ans = n;
	for (int t = 0; t < (1 << n); t++) {
		string aa;
		string bb;
		fori(0, n-1) {
			if ( (t & (1 << i)) > 0 ) {
				aa.push_back(c[i]);
			} else {
				bb.push_back(c[i]);
			}
		}
		if (aa.size() == a.size()) {
			int ans1 = 0;
			fori(0, a.size()-1) {
				ans1 += (a[i] != aa[i]);
			}
			fori(0, b.size() - 1) {
				ans1 += (b[i] != bb[i]);
			}
			ans = min(ans1, ans);
		}
	}
	cout << ans << endl;
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--) solve();	
}

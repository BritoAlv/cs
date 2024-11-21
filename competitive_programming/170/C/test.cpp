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
	int n, k;
	cin >> n >> k;
	map<int, int> fq;
	forn{
		int x;
		cin >> x;
		fq[x]++;
	}
	vector<int> vals;
	for(auto z : fq) {
		vals.push_back(z.first);
	}
	n = vals.size();
	vector<int> ans(n);
	ans[n-1] = fq[vals.back()];
	int last_used = n-1;
	for(int i = n-2; i >= 0; i--) {
		ans[i] = fq[vals[i]];
		if(vals[i+1] - vals[i] == 1) {
			ans[i] += ans[i+1];
			while( vals[last_used] - vals[i] >= k) {
				ans[i] -= fq[vals[last_used]];
				last_used--;
			}
		}
		else {
			last_used = i;
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans[n-1] << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--) solve();
}
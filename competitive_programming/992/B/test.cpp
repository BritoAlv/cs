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

vi starts;

void solve()
{
	int n;
	cin >> n;
	fori(1, starts.size() - 1) {
		if (n <= starts[i] && n > starts[i-1]) {
			cout << i << endl;
			return;
		}
	}
}

int main()
{
	starts.push_back(0);
	starts.push_back(1);
	for (int i = 1; ; i++) {
		int last = starts.back();
		int neww = 2 * (last + 1);
		if (neww > 300000) {
			break;
		}
		starts.push_back(neww);
	}
	int t = 1;
	cin >> t;
	while(t--) solve();	
}

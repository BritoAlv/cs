#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int ans = 0;
		map<int, int> b;
		forn
		{
			int x;
			cin >> x;
			b[x]++;
		}
		for(auto q : b) {
			ans += q.second / 2;
		}
		cout << ans << endl;
	}    
}

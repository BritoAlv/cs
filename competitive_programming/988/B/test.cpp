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
		ll n;
		cin >> n;
		vi a(n);
		map<int, int> b;
		forn
		{
			int x;
			cin >> x;
			b[x]++;
		}
		ll to_find = n-2;
		for(const auto z : b) {
			if(to_find % (z.first) == 0) {
				int other = to_find / z.first;
				if( b[other] > (other == z.first) ) {
					cout << z.first << wp << other << endl;
					break;
				}
			}
		}
	}    
}

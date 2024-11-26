#include <bits/stdc++.h>

#define doo(a) for(int i_i = 0; i_i < a; i_i++) 
#define fori(a,b) for (int i = a; i <= b; i++)
#define forj(a,b) for (int j = a; j <= b; j++)
#define forn  for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define ull unsigned long long
using namespace std;

ull squares(ull x) {
	ull low = 1;
	ull upp = x;
	while(upp - low > 1) {
		ull mid = low + (upp - low)/2;
		if(mid <= 2000000000 && mid * mid <= x) {
			low = mid;
		} else {
			upp = mid - 1;
		}
	}
	while( (low + 1) * (low + 1) <= x ) {
		low++;
	}
	return low;
}

void solve()
{
	ull k;
	cin >> k;
	ull low = k;
	ull upp = 2 * k;
	while(upp - low > 1) {
		ull mid = low + (upp - low)/2;
		if(squares(mid) <= mid - k) {
			upp = mid;
		} else {
			low = mid + 1;
		}
	}
	while(upp - 1 > 0 && squares(upp - 1) <= upp - 1- k) {
		upp--;
	}
	cout << upp << endl;
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--) solve();	
}
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
	int n;
	cin >> n;
	string u = "aeiou";
	int rem = n % 5;
	fori(0, 4) {
		doo(n / 5) {
			cout << u[i];
		}
		if (rem-- > 0) {
			cout << u[i];
		}
	}
	cout << endl;
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--) solve();	
}
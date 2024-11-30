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
	int a, b;
	cin >> a >> b;
	int minn = min(a, b);
	int maxx = max(a, b);
	int gcd = __gcd(minn, maxx);
	cout << minn * maxx / gcd << endl;

}

int main()
{
	int t = 1;
	cin >> t;
	while(t--) solve();	
}

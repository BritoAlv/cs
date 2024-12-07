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

int ceil(int a, int b) {
	return a / b + ((a % b) > 0);
}

void solve()
{
	int n, x, y;
	cin >> n >> x >> y;
	x = min(x, y);
	cout << ceil(n, x)<< endl;
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--) solve();	
}
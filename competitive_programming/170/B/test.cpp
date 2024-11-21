#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

ll mod = 1e9 + 7;

ll f_pow(ll base, ll exp, ll mod)
{
	if (exp == 0)
		return 1;
	if (exp == 1)
		return base % mod;
	ll middle = f_pow(base, exp / 2, mod);
	middle *= middle;
	middle %= mod;
	if (exp % 2)
	{
		middle *= base;
		middle %= mod;
	}
	return middle;
}


int main()
{
	int n = 10;
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
	for(int i = 0; i <= n; i++) {
		dp[i][0] = 1;
		dp[i][n] = 1;
		for(int k = 1 ; k < i; k++) {
			dp[i][k] = dp[i][k-1] + dp[i-1][k-1];
		}
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++) {
			cout << dp[i][j] << (j == n ? '\n' : ' ');
	}}
}

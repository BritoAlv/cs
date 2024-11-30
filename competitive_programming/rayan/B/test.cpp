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
	int n, m, k;
	cin >> n >> m >> k;
	string s;
	cin >> s;
	int ops = 0;
	int consecutive = 0;
	fori(0, n-1) {
		if (s[i] == '1') consecutive = 0;
		else consecutive++;

		if (consecutive == m) {
			forj(i, min(i + k - 1, n-1)) {
				s[j] = '1';
			}
			ops++;
			consecutive = 0;
		}
	}
	cout << ops << endl;
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--) solve();	
}

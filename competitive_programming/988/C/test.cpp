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
		if(n <= 4) {
			cout << -1 << endl;
		}
		else {
			vector<int> ans(n);
			int pt = 0;
			for(int i = 1; i <= n; i+=2)
			{
				ans[pt++] = i;
			}
			for(int i = 2; i <= n; i+=2) {
				ans[pt++] = i;
			}
			if(n >= 7) {
				if(n % 2 == 0)
					swap(ans[n / 2 - 1], ans[3]);
				else
					swap(ans[n / 2], ans[3]);

				forn{
					cout << ans[i] << wp;
				}
				cout << endl;
			}
			else {
				if(n == 5) {
					cout << "1 3 5 4 2" << endl;
				}
				else {
					cout << "1 3 5 4 2 6 " << endl;
				}
			}
		}
	}    
}

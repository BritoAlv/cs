#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;


int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		n *= 2;
		int switches_on = 0;
		forn {
			int x;
			cin >> x;
			switches_on += x == 1;
		}
		cout << switches_on % 2 << wp;
		if(switches_on <= n / 2) {
			cout << switches_on << endl;
		} else {
			cout << n - switches_on << endl;
		}
	}
}
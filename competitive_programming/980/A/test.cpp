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
	while(t--) {
	    int a, b;
	    cin >> a >> b;
	    if(a >= b) {
		    cout << a << endl;
	    }
	    else if(2 * a >= b) {
	    	cout << 2*a - b << endl;
	    }
		else {
			cout << 0 << endl;
		}

	}
}
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
	while (t--) {
		int n;
		cin >> n;
		if (n % 2 == 0) {
			for (int i = 0; i < n; i += 2) {
				cout << i + 1 << wp << i + 1 << wp;
			}
			cout << endl;
		} else {
			if(n < 26) {
				cout << -1 << endl;
			}
			else {
				vector<int> pq(n+1, 0);
				pq[1] = 1;
				pq[2] = 2;
				for(int i = 3; i <= 16; i+=2) {
					pq[i] =i+1;
					pq[i+1] =i+1;
				}
				pq[17] = 1;
				for(int i = 18; i < 26; i+=2) {
					pq[i] =i+1;
					pq[i+1] =i+1;
				}
				pq[26] = 1;
				pq[27] = 2;
				for(int i = 28; i <= n; i+=2) {
					pq[i] = i+1;
					pq[i+1] =i+1;
				}

				forn
				{
					cout << pq[i+1] << wp;
				}
				cout << endl;
			}
		}
	}
}

#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

int d(pi A, pi B) {
	return (A.second - B.second)*(A.second - B.second) + (A.first - B.first)*(A.first - B.first);
}

void solve() {
	int x, y, k;
	cin >> x >> y >> k;
	for(int j = 0; j <= x; j++) {
		pi B = {x - j, y};
		pi D = {0, x - j};
		if(x - j <= y) {
			for (int i = 0; i <= y; i++) {
				pi A = {0, i};
				pi C = {y - i, 0};
				if (y - i <= x && d(A, B) >= k && d(C, D) >= k) {
					printf("%d %d %d %d \n", A.first, A.second, B.first, B.second);
					printf("%d %d %d %d \n", C.first, C.second, D.first, D.second);
					return;
				}
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}

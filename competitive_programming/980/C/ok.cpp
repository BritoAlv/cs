#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

vector<vector<int> > b;
ll best = -1;

void solve(vector<int> &p, vector<pi > &A) {
	int n = p.size();
	vector<int> q(2 * n);
	ll inv = 0;
	int pt = 0;
	forn {
		q[pt++] = A[p[i]].first;
		q[pt++] = A[p[i]].second;
	}
	for (int i = 0; i < 2 * n; i++) {
		for (int j = i + 1; j < 2 * n; j++) {
			inv += q[i] > q[j];
		};
	}
	if (best == -1 || inv <= best) {
		if (best == inv)
			b.push_back(q);
		else
			b = {q};
		best = inv;
	}
}

int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pi > A(n);
		vector<int> p(n);
		forn {
			p[i] = i;
			cin >> A[i].first >> A[i].second;
		}
		solve(p, A);
		while (next_permutation(p.begin(), p.end())) {
			solve(p, A);
		}
		cout << best << endl;
		for (auto bb: b) {
			for (int i = 0; i < 2 * n; i++) {
				cout << bb[i] << wp;
			}
			cout << endl;
		}
	}
}

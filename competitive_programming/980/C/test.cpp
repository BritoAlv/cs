#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

ll countAndMerge(vector<int> &arr, int l, int m, int r) {
	// Counts in two subarrays
	int n1 = m - l + 1, n2 = r - m;

	// Set up two vectors for left and right halves
	vector<int> left(n1), right(n2);
	for (int i = 0; i < n1; i++)
		left[i] = arr[i + l];
	for (int j = 0; j < n2; j++)
		right[j] = arr[m + 1 + j];

	// Initialize inversion count (or result) and merge two halves
	ll res = 0;
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		// No increment in inversion count if left[] has a
		// smaller or equal element
		if (left[i] <= right[j])
			arr[k++] = left[i++];

		// If right is smaller, then it is smaller than n1-i
		// elements because left[] is sorted
		else {
			arr[k++] = right[j++];
			res += (n1 - i);
		}
	}

	// Merge remaining elements
	while (i < n1)
		arr[k++] = left[i++];
	while (j < n2)
		arr[k++] = right[j++];

	return res;
}

// Function to count inversions in the array
ll countInv(vector<int> &arr, int l, int r) {
	ll res = 0;
	if (l < r) {
		int m = (r + l) / 2;

		// Recursively count inversions in the left and
		// right halves
		res += countInv(arr, l, m);
		res += countInv(arr, m + 1, r);

		// Count inversions such that greater element is in
		// the left half and smaller in the right half
		res += countAndMerge(arr, l, m, r);
	}
	return res;
}

ll inversionCount(vector<int> &arr) {
	int n = arr.size();
	return countInv(arr, 0, n - 1);
}

vector<int> b;
ll best = -1;

void solve2(vector<int> &p, vector<pi > &A) {
	int n = p.size();
	vector<int> q(2 * n);
	vector<int> qq(2 * n);
	int pt = 0;
	forn {
		q[pt++] = A[p[i]].first;
		q[pt++] = A[p[i]].second;
	}
	for(int i = 0; i < 2 * n; i++) {
		qq[i] = q[i];
	}
	ll inv = inversionCount(q);
	if (best == -1 || inv <= best) {
		b = qq;
		best = inv;
	}
}

void solve() {
	best = -1;
	int n;
	cin >> n;
	vector<pi > A(n);
	vector<int> p(n);
	forn {
		p[i] = i;
		cin >> A[i].first >> A[i].second;
	}
	vector<pair<pi, int> > P(n);
	forn {
		P[i] = {{min(A[i].first, A[i].second), max(A[i].first, A[i].second) }, i};
	}
	sort(P.begin(), P.end());
	forn {
		p[i] = P[i].second;
	}
	solve2(p, A);
	for (int i = 0; i < 2 * n; i++) {
		cout << b[i] << wp;
	}
	cout << endl;
	//cout << best << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}

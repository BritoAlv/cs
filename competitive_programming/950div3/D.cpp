// Problem: D. GCD-sequence
// Contest: Codeforces - Codeforces Round 950 (Div. 3)
// URL: https://codeforces.com/contest/1980/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

int mcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  if (a > b) {
    return mcd(b, a);
  }
  if (b % a == 0) {
    return a;
  } else {
    return mcd(a, b % a);
  }
}

int check(vector<int> &a) {
  int n = a.sz;
  for (int i = 2; i < n; i++) {
    if (mcd(a[i], a[i - 1]) < mcd(a[i - 1], a[i - 2])) {
      return 0;
    }
  }
  return 1;
}

void Solve() {
  int n;
  cin >> n;
  int a[n];
  forn { cin >> a[i]; }
  for (int i = n - 3; i >= 0; i--) {
    if (mcd(a[i], a[i + 1]) > mcd(a[i + 1], a[i + 2])) {
      vector<int> arr1;
      for (int j = 0; j < n; j++) {
        if (j != i) {
          arr1.pb(a[j]);
        }
      }
      vector<int> arr2;
      for (int j = 0; j < n; j++) {
        if (j != i + 1) {
          arr2.pb(a[j]);
        }
      }
      vector<int> arr3;
      for (int j = 0; j < n; j++) {
        if (j != i + 2) {
          arr3.pb(a[j]);
        }
      }
      if (check(arr1) || check(arr2) || check(arr3)) {
        break;
      } else {
        cout << "No" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int test_cases;
  cin >> test_cases;
  while (test_cases-- > 0) {
    Solve();
  }
  return 0;
}

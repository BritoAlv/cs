// Problem: A. Problem Generator
// Contest: Codeforces - Codeforces Round 950 (Div. 3)
// URL: https://codeforces.com/contest/1980/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

void BruteSolve() { return; }

void Solve() {
  int n, m;
  cin >> n >> m;
  map<int, int> counts;
  counts['A'] = 0;
  counts['B'] = 0;
  counts['C'] = 0;
  counts['D'] = 0;
  counts['E'] = 0;
  counts['F'] = 0;
  counts['G'] = 0;
  forn {
    char t;
    cin >> t;
    counts[t]++;
  }
  int ans = 0;
  for (auto x : counts) {
    ans += max(0, m - x.second);
  }
  cout << ans << endl;
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

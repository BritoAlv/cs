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

void Solve() {
  string s;
  cin >> s;
  int n = s.sz;
  map<string, int> counts;
  for (int l = 0; l < n; l++) {
    for (int r = l; r < n; r++) {
      string m = "";
      for (int j = l; j <= r; j++) {
        m += s[j];
      }
      sort(m.begin(), m.end());
      if (counts.find(m) == counts.end()) {
        counts[m] = 0;
      }
      counts[m]++;
    }
  }
  long long ans = 0;
  for (auto x : counts) {
    ans += (x.second * (x.second - 1)) / 2;
  }
  cout << ans << endl;
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int test_cases = 1;
  while (test_cases-- > 0) {
    Solve();
  }
  return 0;
}
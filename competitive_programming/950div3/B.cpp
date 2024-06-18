// Problem: B. Choosing Cubes
// Contest: Codeforces - Codeforces Round 950 (Div. 3)
// URL: https://codeforces.com/contest/1980/problem/B
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
  int n, f, k;
  cin >> n >> f >> k;
  f--;
  pi favorite;
  vector<pi> cubes;
  forn {
    int x;
    cin >> x;
    cubes.pb({x, i});
  }
  favorite = cubes[f];
  sort(cubes.begin(), cubes.end(), greater<pi>());
  set<pi> candidates;
  fork { candidates.insert(cubes[i]); }
  int flag = 0;
  for (int i = k; i < n; i++) {
    if (i > 0 && cubes[i].first == favorite.first &&
        cubes[i].first == cubes[i - 1].first) {
      candidates.insert(cubes[i]);
      flag = 1;
    } else {
      break;
    }
  }
  if (candidates.find(favorite) == candidates.end()) {
    cout << "No" << endl;
  } else {
    cout << (!flag ? "Yes" : "Maybe") << endl;
  }
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

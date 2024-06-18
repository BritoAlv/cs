// Problem: C. Sofia and the Lost Operations
// Contest: Codeforces - Codeforces Round 950 (Div. 3)
// URL: https://codeforces.com/contest/1980/problem/C
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

void Solve() {
  int n;
  cin >> n;
  int a[n];
  int b[n];
  forn { cin >> a[i]; }
  forn { cin >> b[i]; }
  int m;
  cin >> m;
  map<int, int> needs;
  int number_needs = 0;
  forn {
    if (a[i] != b[i]) {
      number_needs++;
      if (needs.find(b[i]) == needs.end()) {
        needs[b[i]] = 0;
      }
      needs[b[i]]++;
    }
  }
  set<int> bb;
  forn { bb.insert(b[i]); }
  int flag = 0;
  form {
    int x;
    cin >> x;
    if (needs.find(x) == needs.end()) {
      if (bb.find(x) == bb.end()) {
        flag = 1;
      } else {
        flag = 0;
      }
    } else {
      if (needs[x] > 0) {
        needs[x]--;
        number_needs--;
      }
      flag = 0;
    }
  }

  cout << (number_needs == 0 && !flag ? "YES" : "NO") << endl;
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

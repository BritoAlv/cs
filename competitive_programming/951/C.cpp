// Problem: C. Earning on Bets
// Contest: Codeforces - Codeforces Round 951 (Div. 2)
// URL: https://codeforces.com/contest/1979/problem/C
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

void BruteSolve() { return; }

long long min_value(long long sum, long long ki) { return sum / ki + 1; }

int n;
long long k[50];
int dd(long long sum) {
  long long sum_mins = 0;
  vector<int> mins(n);
  forn {
    mins[i] = min_value(sum, k[i]);
    sum_mins += mins[i];
  }
  if (sum_mins <= sum) {
    mins[n - 1] += sum - sum_mins;
    forn { cout << mins[i] << wp; }
    cout << endl;
    return 1;
  }
  return 0;
}

void Solve() {
  cin >> n;
  forn { cin >> k[i]; }
  if (!dd(1e9 - 1)) {
    cout << -1 << endl;
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

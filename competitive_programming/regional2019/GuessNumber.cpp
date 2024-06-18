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

vector<double> dp;
int n, v;

void aument(int x) {
  vector<double> bits(n, 0);
  double sum = n;
  forn { bits[i] = (x & (1ll << i)) > 0; }
  for (int i = n - 1; i >= 0; i--) {
    if (bits[i] == 0) {
      sum -= 1;
    } else {
      break;
    }
  }
  if (bits[v] == 0) {
    return;
  }
  forn {
    if (bits[i]) {
      // we are in this subset x and want to add the probability of going to
      // subset x - (1 << i)
      double prob = 1;
      int j = i;
      while (j - 1 >= 0 && bits[j - 1] == 0) {
        prob += 1;
        j--;
      }
      dp[x - (1ll << i)] += dp[x] * (prob / sum);
    }
  }
}

int count_zeros(int i) {
  int ans = 0;
  for (int j = 0; j < n; j++) {
    ans += ((i & (1ll << j)) == 0);
  }
  return ans;
}

void Solve() {
  // bit active means number has not been choosen yet.
  cin >> n >> v;
  v--;
  dp = vector<double>((1ll << n), 0);
  dp[(1ll << n) - 1] = 1;
  map<int, vector<long long>> vals;
  for (int i = 0; i <= n; i++) {
    vals[i] = vector<long long>();
  }
  for (int i = 0; i < (1 << n); i++) {
    vals[count_zeros(i)].pb(i);
  }

  for (int active = n; active >= 0; active--) {
    for (auto i : vals[n - active]) {
      aument(i);
    }
  }
  double ans = 0;
  for (int i = 0; i < (1ll << n); i++) {
    if ((i & (1 << v)) == 0) {
      ans += dp[i] * count_zeros(i);
    }
  }
  cout << setprecision(9);
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
#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<long long, long long>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

long long MOD = 998244353;

pi solve_diop(long long a, long long b) {
  if (a < 0) {
    auto temp = solve_diop(-a, b);
    temp.first = -temp.first;
    return temp;
  }
  if (b < 0) {
    auto temp = solve_diop(a, -b);
    temp.second = -temp.second;
    return temp;
  }
  if (a < b) {
    auto ans = solve_diop(b, a);
    long long temp = ans.first;
    ans.first = ans.second;
    ans.second = temp;
    return ans;
  }
  if (b == 1) {
    return {-1, a + 1};
  }
  auto anss = solve_diop(a - (a / b) * b, b);
  return {anss.first, anss.second - (a / b) * anss.first};
}

long long get_inverse(long long n, long long mod) {
  /*
  compute the inverse of n mod mod
  */
  // return fast_˚exponentiation(n, mod - 2, mod);
  if (n == 0) {
    return 1;  // this works ? but doesn't make sense.
  }
  auto ans = solve_diop(mod, n).second;
  while (ans < 0) {
    ans += mod;
  }
  return ans;
}

struct FenwickTree {
  vector<int> bit;  // binary indexed tree
  int n;

  FenwickTree(int n) {
    this->n = n;
    bit.assign(n, 0);
  }

  FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
  }

  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
    return ret;
  }

  int sum(int l, int r) { return sum(r) - sum(l - 1); }

  void add(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
  }
};

void Solve() {
  int n;
  cin >> n;
  long long a[n];
  forn { cin >> a[i]; }
  long long dp1[n];
  set<int> A;
  forn { A.insert(a[i]); }
  int pt = 0;
  map<int, int> positions;
  for (auto x : A) {
    positions[x] = pt++;
  }
  FenwickTree tr(A.sz);
  for (int i = n - 1; i >= 0; i--) {
    tr.add(positions[a[i]], 1);
    dp1[i] = 0;
    if (positions[a[i]] > 0) {
      dp1[i] = tr.sum(positions[a[i]] - 1);
    }
    dp1[i] %= MOD;
  }
  long long dp2[n];
  dp2[n - 1] = 1;
  map<int, int> counts;
  counts[a[n - 1]] = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (counts.find(a[i]) == counts.end()) {
      counts[a[i]] = 0;
    }
    counts[a[i]]++;
    dp2[i] = (n - i - 1) % MOD;
    dp2[i] *= dp2[i + 1];
    dp2[i] %= MOD;
    dp2[i] *= get_inverse(counts[a[i]], MOD);
    dp2[i] %= MOD;
  }
  long long ans = 0;
  forn {
    ans += (dp1[i] * dp2[i]) % MOD;
    ans %= MOD;
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
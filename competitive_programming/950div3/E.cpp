// Problem: E. Permutation of Rows and Columns
// Contest: Codeforces - Codeforces Round 950 (Div. 3)
// URL: https://codeforces.com/contest/1980/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
  vector<vector<long long>> board1(n, vector<long long>(m));
  vector<vector<long long>> board2(n, vector<long long>(m));
  vector<vector<long long>> board3(m, vector<long long>(n));
  vector<vector<long long>> board4(m, vector<long long>(n));
  set<vector<long long>> xx1;
  set<vector<long long>> xx2;
  set<vector<long long>> xx3;
  set<vector<long long>> xx4;
  forn {
    form {
      cin >> board1[i][j];
      board3[j][i] = board1[i][j];
    }
  }
  forn {
    form {
      cin >> board2[i][j];
      board4[j][i] = board2[i][j];
    }
  }
  forn {
    sort(board1[i].begin(), board1[i].end());
    sort(board2[i].begin(), board2[i].end());
    xx1.insert(board1[i]);
    xx2.insert(board2[i]);
  }
  form {
    sort(board3[j].begin(), board3[j].end());
    sort(board4[j].begin(), board4[j].end());
    xx3.insert(board3[j]);
    xx4.insert(board4[j]);
  }
  cout << ((xx1 == xx2 && xx3 == xx4) ? "YES" : "NO") << endl;
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

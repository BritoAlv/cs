// Problem: C. Choose the Different Ones!
// Contest: Codeforces - Codeforces Round 923 (Div. 3)
// URL: https://codeforces.com/contest/1927/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back
#define ull unsigned long long

// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    set<int> A;
    set<int> B;
    forn
    {
        int c;
        cin >> c;
        A.insert(c);
    }
    form
    {
        int c;
        cin >> c;
        B.insert(c);
    }
    vector<int> state_a(k);
    vector<int> state_b(k);
    int used_a = 0;
    int used_b = 0;
    for (int i = 0; i < k; i++)
    {
        state_a[i] = (A.find(i + 1) != A.end());
        state_b[i] = (B.find(i + 1) != B.end());
        if (state_a[i] + state_b[i] == 0)
        {
            cout << "NO" << endl;
            return;
        }
        if (state_a[i] == 1 && state_b[i] == 0)
        {
            used_a++;
        }
        if (state_b[i] == 1 && state_a[i] == 0)
        {
            used_b++;
        }
    }
    if (used_a > k / 2 || used_b > k / 2)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        cout << "YES" << endl;
    }
    return;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}

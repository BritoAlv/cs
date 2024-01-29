// Problem: E. Making Anti-Palindromes
// Contest: Codeforces - Codeforces Round 867 (Div. 3)
// URL: https://codeforces.com/contest/1822/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vector<char> a(n);
    forn
    {
        cin >> a[i];
    }
    if (n % 2 == 1)
    {
        cout << -1 << endl;
        return;
    }
    int ops = 0;
    vector<set<int>> A;
    for (int i = 0; i < 26; i++)
    {
        A.pb(set<int>());
    }

    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] == a[n - 1 - i])
        {
            A[a[i] - 'a'].insert(i);
        }
    }
    while (true)
    {
        int f = 0;
        vector<pair<int, int>> P;
        for (int i = 0; i < 26; i++)
        {
            if (A[i].size() > 0)
            {
                P.pb({A[i].size(), i});
            }
        }
        sort(P.begin(), P.end());
        if (P.size() >= 2)
        {
            int max_size = P[P.size() - 1].second;
            int j = P[P.size() - 2].second;

            if (j != max_size && A[j].size() > 0)
            {
                int from_i = *A[max_size].begin();
                int from_j = *A[j].begin();

                A[max_size].erase(from_i);
                A[j].erase(from_j);

                char temp = a[from_i];
                a[from_i] = a[from_j];
                a[from_j] = temp;
                ops++;
                f = 1;
            }
        }

        if (!f)
        {
            break;
        }
    }

    char wrong = a[0];
    int n_pairs = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] == a[n - 1 - i])
        {
            wrong = a[i];
            n_pairs++;
        }
    }
    int others = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != wrong && a[n - 1 - i] != wrong)
        {
            others++;
        }
    }
    if (n_pairs <= others)
    {
        cout << ops + n_pairs << endl;
    }
    else
    {
        cout << -1 << endl;
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
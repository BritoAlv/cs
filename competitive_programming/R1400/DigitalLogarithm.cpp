// Problem: C. Digital Logarithm
// Contest: Codeforces - Educational Codeforces Round 135 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1728/C
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
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    map<int, int> A;
    map<int, int> B;
    forn
    {
        int c;
        cin >> c;
        if (A.find(c) == A.end())
        {
            A[c] = 0;
        }
        A[c]++;
    }
    forn
    {
        int c;
        cin >> c;
        if (B.find(c) == B.end())
        {
            B[c] = 0;
        }
        B[c]++;
    }
    for (auto x : B)
    {
        int cant = x.second;
        int c = x.first;
        if (A.find(c) != A.end())
        {
            int to_quit = min(A[c], cant);
            A[c] -= to_quit;
            B[c] -= to_quit;
        }
    }

    ull ans = 0;
    for (auto x : A)
    {
        if (x.second > 0 && x.first >= 10)
        {
            ans += x.second;
            int z = x.first;
            int o = 0;
            while (z > 0)
            {
                z /= 10;
                o++;
            }
            if (A.find(o) == A.end())
            {
                A[o] = 0;
            }
            A[o] += x.second;
            A[x.first] = 0;
        }
    }

    for (auto x : B)
    {
        if (x.second > 0 && x.first >= 10)
        {
            ans += x.second;
            int z = x.first;
            int o = 0;
            while (z > 0)
            {
                z /= 10;
                o++;
            }
            if (B.find(o) == B.end())
            {
                B[o] = 0;
            }
            B[o] += x.second;
            B[x.first] = 0;
        }
    }

    for (auto x : B)
    {
        int cant = x.second;
        int c = x.first;
        if (A.find(c) != A.end())
        {
            int to_quit = min(A[c], cant);
            A[c] -= to_quit;
            B[c] -= to_quit;
        }
    }

    for (auto x : A)
    {
        if (x.first != 1)
            ans += x.second;
    }
    for (auto x : B)
    {
        if (x.first != 1)
            ans += x.second;
    }
    cout << ans << endl;
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

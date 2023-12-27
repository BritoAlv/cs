// Problem: A. Constructive Problem
// Contest: Codeforces - Codeforces Round 866 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1819/A
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

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    forn
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    int mex = b[n - 1] + 1;
    forn
    {
        if (i == 0 && b[i] != 0)
        {
            mex = 0;
            break;
        }
        if (i > 0)
        {
            if (b[i] != b[i - 1] && b[i] != b[i - 1] + 1)
            {
                mex = b[i - 1] + 1;
                break;
            }
        }
    }
    if (b[n - 1] <= mex)
    {
        for (int i = 1; i < n; i++)
        {
            if (b[i] == b[i - 1])
            {
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
        return;
    }
    else
    {
        set<int> A;
        forn
        {
            A.insert(a[i]);
        }
        if (A.find(mex + 1) == A.end())
        {
            cout << "YES" << endl;
            return;
        }
        else
        {
            vector<int> positions;
            forn
            {
                if (a[i] == mex + 1)
                {
                    positions.pb(i);
                }
            }
            for (int i = positions[0]; i <= positions[positions.size() - 1]; i++)
            {
                a[i] = mex;
            }
            forn
            {
                b[i] = a[i];
            }
            sort(b, b + n);
            int mexx = b[n - 1] + 1;
            forn
            {
                if (i == 0 && b[i] != 0)
                {
                    mexx = 0;
                    break;
                }
                if (i > 0)
                {
                    if (b[i] != b[i - 1] && b[i] != b[i - 1] + 1)
                    {
                        mexx = b[i - 1] + 1;
                        break;
                    }
                }
            }
            if (mex + 1 == mexx)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
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
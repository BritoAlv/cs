// Problem: B. Swap and Reverse
// Contest: Codeforces - Harbour.Space Scholarship Contest 2023-2024 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1864/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: parity of k,
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<char> S(n);
    forn
    {
        cin >> S[i];
    }
    if (k % 2 == 1)
    {
        vector<char> odds;
        vector<char> evens;
        forn
        {
            if (i % 2 == 0)
            {
                odds.push_back(S[i]);
            }
            else
            {
                evens.push_back(S[i]);
            }
        }
        sort(odds.begin(), odds.end());
        sort(evens.begin(), evens.end());
        int index_odd = 0;
        int index_even = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                cout << odds[index_odd];
                index_odd++;
            }
            else
            {
                cout << evens[index_even];
                index_even++;
            }
        }
        cout << endl;
    }
    else
    {
        sort(S.begin(), S.end());
        forn
        {
            cout << S[i];
        }
        cout << endl;
    }

    return;
}

int main()
{
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}

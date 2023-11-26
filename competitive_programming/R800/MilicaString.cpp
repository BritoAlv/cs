// Problem: A. Milica and String
// Contest: Codeforces - Codeforces Round 910 (Div. 2)
// URL: https://codeforces.com/contest/1898/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<char> S(n);
    int A_count = 0;
    int B_count = 0;
    forn
    {
        cin >> S[i];
        A_count += (S[i] == 'A');
        B_count += (S[i] == 'B');
    }

    if (B_count == k)
    {
        cout << 0 << endl;
    }
    else if (B_count < k)
    {
        int AA_count = 0;
        int index = 0;
        while (AA_count < k - B_count)
        {
            AA_count += (S[index] == 'A');
            if (AA_count == k - B_count)
            {
                cout << 1 << endl;
                cout << index + 1 << wp << 'B' << endl;
                return;
            }
            index++;
        }
    }
    else
    {
        int BB_count = 0;
        int index = 0;
        while (BB_count < B_count - k)
        {
            BB_count += (S[index] == 'B');
            if (BB_count == B_count - k)
            {
                cout << 1 << endl;
                cout << index + 1 << wp << 'A' << endl;
            }
            index++;
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

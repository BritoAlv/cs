// Problem: B. Asterisk-Minor Template
// Contest: Codeforces - Educational Codeforces Round 144 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1796/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: noticed that only match at borders or at substring of
// size == 2.
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
    string A, B;
    cin >> A >> B;
    if (A[0] == B[0])
    {
        cout << "YES" << endl;
        cout << A[0] << '*' << endl;
        return;
    }
    if (A[A.size() - 1] == B[B.size() - 1])
    {
        cout << "YES" << endl;
        cout << '*' << A[A.size() - 1] << endl;
        return;
    }

    if (A.size() >= 2 && B.size() >= 2)
    {
        for (int i = 0; i + 1 < A.size(); i++)
        {
            for (int j = 0; j + 1 < B.size(); j++)
            {
                if (A[i] == B[j] && A[i + 1] == B[j + 1])
                {
                    cout << "YES" << endl;
                    if (!(i == 0 && j == 0))
                    {
                        cout << '*';
                    }
                    cout << A[i] << A[i + 1];
                    if (!(i == A.size() - 2 && j == B.size() - 2))
                    {
                        cout << '*';
                    }
                    cout << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
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

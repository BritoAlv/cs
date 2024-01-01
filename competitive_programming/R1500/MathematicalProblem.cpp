// Problem: D. Mathematical Problem
// Contest: Codeforces - Good Bye 2023
// URL: https://codeforces.com/contest/1916/problem/D
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

vector<vector<string>> A;

void init()
{
    for (int i = 1; i <= 99; i++)
    {
        vector<string> B;
        if (i % 2)
        {
            if (i == 1)
            {
                B.pb("1");
            }
            else if (i == 3)
            {
                B.pb("169");
                B.pb("196");
                B.pb("961");
            }
            else
            {
                for (auto x : A[i - 3])
                {
                    B.pb(x + "00");
                }
                string one = "9";
                for (int j = 0; j < i / 2 - 1; j++)
                {
                    one += "0";
                }
                one += "6";
                for (int j = 0; j < i / 2 - 1; j++)
                {
                    one += "0";
                }
                one += "1";

                string two = "1";
                for (int j = 0; j < i / 2 - 1; j++)
                {
                    two += "0";
                }
                two += "6";
                for (int j = 0; j < i / 2 - 1; j++)
                {
                    two += "0";
                }
                two += "9";
                B.pb(one);
                B.pb(two);
            }
        }
        A.pb(B);
    }
}

void Solve()
{
    int n;
    cin >> n;
    for (auto x : A[n - 1])
    {
        cout << x << endl;
    }
    return;
}

int main()
{
    init();
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}

// Problem: B. NIT Destroys the Universe
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/problemset/problem/1696/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Math Proof: test cases looks weird, and weak, answer is at most 2.
// the way of looping over the array is like an automaton, but don't'
// know how implement it by now.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    bool found_positive = false;
    bool expect_zero = false;
    bool wrong = false;
    while (n > 0)
    {
        int t;
        cin >> t;
        if (t > 0)
        {
            found_positive = true;
        }

        if (t == 0 && found_positive)
        {
            expect_zero = true;
        }

        if (t > 0 && expect_zero)
        {
            wrong = true;
        }
        n--;
    }
    if (wrong)
    {
        cout << 2 << endl;
    }
    else if (found_positive)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
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

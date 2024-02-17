// Problem: C. Fishingprince Plays With Array
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/C
// Memory Limit: 512 MB
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
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> a;
    forn
    {
        int c;
        cin >> c;
        int t = c;
        while (t % m == 0)
        {
            t /= m;
        }
        a.push({t, c / t});
    }
    int k;
    cin >> k;
    ull b[k];
    for (int i = 0; i < k; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < k; i++)
    {
        ull c = b[i];
        if (a.size() == 0)
        {
            cout << "No" << endl;
            return;
        }
        if (c % a.front().first != 0)
        {
            cout << "No" << endl;
            return;
        }
        else
        {
            int pow = c / a.front().first;
            int pow2 = pow;
            int exp = 0;
            while (pow % m == 0)
            {
                pow /= m;
                exp++;
            }
            if (pow != 1)
            {
                cout << "No" << endl;
                return;
            }
            int expected = a.front().first;
            // need pow2 elements = expected.!!
            int current = a.front().second;
            while (current < pow2)
            {
                a.pop();
                if (a.size() == 0 || a.front().first != expected)
                {
                    cout << "No" << endl;
                    return;
                }
                else
                {
                    current += a.front().second;
                }
            }
            if (current > pow2)
            {
                //
                a.front().second = (current - pow2);
            }
            else
            {
                a.pop();
            }
        }
    }
    if (a.size() == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
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
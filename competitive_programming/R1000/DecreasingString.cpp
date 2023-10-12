// Problem: C. Decreasing String
// Contest: Codeforces - Educational Codeforces Round 156 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1886/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
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
    string s;
    long long pos;
    cin >> s >> pos;
    int start = s.size();
    while (pos - start > 0)
    {
        pos -= start;
        start--;
    }
    int cant_letter = s.size() - start;
    list<char> lk;
    for (auto cha : s)
    {
        lk.push_back(cha);
    }
    auto itt = lk.begin();
    while (cant_letter > 0)
    {
        while (itt != (prev(lk.end(), 1)) && *itt <= *next(itt, 1))
        {
            itt++;
        }
        // delete node at itt and now loop back erasing everything.
        if (itt == (prev(lk.end(), 1)))
        {
            while (cant_letter > 0)
            {
                if (itt == lk.begin())
                {
                    itt = next(itt, 1);
                    lk.erase(prev(itt, 1));
                }
                else
                {
                    itt = prev(itt, 1);
                    lk.erase(next(itt, 1));
                }
                cant_letter--;
            }
            break;
        }
        else
        {
            while ((*itt) > *next(itt, 1))
            {
                if (itt == lk.begin())
                {
                    itt = next(itt, 1);
                    lk.erase(prev(itt, 1));
                }
                else
                {
                    itt = prev(itt, 1);
                    lk.erase(next(itt, 1));
                }
                cant_letter--;
                if (cant_letter == 0)
                {
                    break;
                }
            }
        }
    }
    pos--;
    auto it = lk.begin();
    while (pos > 0)
    {
        it++;
        pos--;
    }
    cout << *it;
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
// Problem: B. Deja Vu
// Contest: Codeforces - Codeforces Round 907 (Div. 2)
// URL: https://codeforces.com/contest/1891/problem/B
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

void Solve()
{
    int n, q;
    cin >> n >> q;
    long long a[n];
    forn
    {
        cin >> a[i];
    }
    vector<int> x;
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (x.size() == 0 || x[x.size() - 1] > t)
        {
            x.push_back(t);
        }
    }
    forn
    {
        int copy = a[i];
        int lgptwo = 0;
        while (copy > 0 && copy % 2 == 0)
        {
            lgptwo++;
            copy /= 2;
        }
        for (int j = 0; j < x.size(); j++)
        {
            if (x[j] <= lgptwo)
            {
                for (int z = j; z < x.size(); z++)
                {
                    a[i] += (1 << (x[z] - 1));
                }
                break;
            }
        }
        cout << a[i] << wp;
    }
    cout << endl;

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

// Problem: B. Interesting drink
// Contest: Codeforces - Codeforces Round 367 (Div. 2)
// URL: https://codeforces.com/contest/706/problem/B
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

int get_index(int r, int start, int end, int a[])
{
    /*
    return index of greatest element in the array that is less or equal than r.
    */
    if (start == end)
    {
        return start;
    }
    else if (end - start == 1)
    {
        if (r >= a[end])
        {
            return end;
        }
        else
        {
            return start;
        }
    }
    else
    {
        int middle = (start + end) / 2;
        if (r >= a[middle])
        {
            return get_index(r, middle, end, a);
        }
        else
        {
            return get_index(r, start, middle - 1, a);
        }
    }
}

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int q;
    cin >> q;
    while (q > 0)
    {
        int r;
        cin >> r;

        if (r >= a[n - 1]) // if the money is more then all prices
        {
            cout << n << endl;
        }

        else if (r < a[0]) // if the money can't afford cheaper answer is 0.
        {
            cout << 0 << endl;
        }

        else // money is at least in some index,
        {
            cout << get_index(r, 0, n - 1, a) + 1 << endl;
        }
        q--;
    }
    return;
}

int main()
{
    Solve();
    return 0;
}
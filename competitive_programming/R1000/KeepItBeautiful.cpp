// Problem: B. Keep it Beautiful
// Contest: Codeforces - Educational Codeforces Round 150 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1841/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Math Proof: this is a fsm but I don't know program that, so
// it gets done by hand'
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
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    cout << 1;
    int start_k = 1; // why ?
    while (start_k < n && a[start_k] >= a[start_k - 1])
    {
        cout << 1;
        start_k++;
    }
    if (start_k == n)
    {
        cout << endl;
        return;
    }
    bool insert_special = false;
    int last_element = a[start_k - 1];
    for (int i = start_k; i < n; i++)
    {
        if (insert_special)
        {
            if (a[i] >= last_element && a[i] <= a[0])
            {
                cout << 1;
                last_element = a[i];
            }
            else
            {
                cout << 0;
            }
        }
        else
        {
            if (a[i] >= last_element)
            {
                cout << 1;
                last_element = a[i];
            }
            else if (a[i] <= a[0])
            {
                cout << 1;
                last_element = a[i];
                insert_special = true;
            }
            else
            {
                cout << 0;
            }
        }
    }
    cout << endl;

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
// Problem: B. Settlement of Guinea Pigs
// Contest: Codeforces - Codeforces Round 857 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1802/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    int n;
    cin >> n;
    int jaulas_no_free = 0;
    int jaulas_free = 0;
    int animales_stored = 0;
    while (n > 0)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            if (jaulas_free == 0)
            {
                jaulas_no_free++;
            }
            else
            {
                jaulas_free--;
                jaulas_no_free++;
            }
            animales_stored++;
        }
        else
        {
            if (animales_stored > 0)
            {
                int temp1 = jaulas_free;
                int temp2 = jaulas_no_free;
                jaulas_free = (temp1 + temp2) - (animales_stored + 2) / 2;
                jaulas_no_free = temp1 + temp2 - jaulas_free;
            }
        }
        n--;
    }
    cout << jaulas_free + jaulas_no_free << endl;
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
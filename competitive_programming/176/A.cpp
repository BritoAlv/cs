// Problem: A. To Zero
// Contest: Codeforces - Educational Codeforces Round 176 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2075/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

// je m appelle Alvaro Brito. J ai 22 ans.
#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>

int test_cases;
using namespace std;

int ceil(int a, int b)
{
    if (a <= 0)
        return 0;
    return a / b + (a % b != 0);
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    if (k % 2 == 0)
    {
        if (n % 2 == 0)
        {
            cout << ceil(n, k) << endl;
        }
        else
        {
            cout << 1 + ceil(n - (k - 1), k) << endl;
        }
    }
    else
    {
        if (n % 2 == 1)
        {
            cout << 1 + ceil(n - k, k - 1) << endl;
        }
        else
        {
            cout << ceil(n, k - 1) << endl;
        }
    }
}

int main()
{
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}

// Problem: E. G-C-D, Unlucky!
// Contest: Codeforces - Codeforces Round 1037 (Div. 3)
// URL: https://codeforces.com/contest/2126/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// You might break and that's okay.
// Tags:
#include <bits/stdc++.h>

#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define wp " "
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>

int test_cases;
using namespace std;

template <typename T> void print(const T &container)
{
    for (const auto &element : container)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

void Solve()
{
    int n;
    cin >> n;
    vl a(n);
    vl b(n);
    vl c(n);
    fori(0, n - 1) cin >> a[i];
    fori(0, n - 1) cin >> b[i];
    fori(0, n - 1) c[i] = (a[i] * b[i] / __gcd(a[i], b[i]));
    vl p(n);
    vl s(n);
    print(c);
    fori(0, n - 1)
    {
        p[i] = c[i];
        if (i > 0)
            p[i] = __gcd(p[i], p[i - 1]);
        if (p[i] != a[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        s[i] = c[i];
        if (i < n - 1)
            s[i] = __gcd(s[i], s[i + 1]);
        if (s[i] != b[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
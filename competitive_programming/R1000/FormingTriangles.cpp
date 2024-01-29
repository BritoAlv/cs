// Problem: B. Forming Triangles
// Contest: Codeforces - Educational Codeforces Round 161 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1922/problem/B
// Memory Limit: 256 MB
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
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    map<int, int> A;
    ull ans = 0;
    forn
    {
        int b;
        cin >> b;
        if (A.find(b) == A.end())
        {
            A[b] = 0;
        }
        A[b]++;
    }
    int counter = 0; // how many from before.
    for (auto x : A)
    {
        int count = x.second;
        if (count >= 3)
        {
            ull aport = x.second;
            aport *= (x.second - 1);
            aport *= (x.second - 2);
            aport /= 6;
            ans += aport;
        }
        if (counter > 0 && count >= 2)
        {
            ull aport = x.second;
            aport *= (x.second - 1);
            aport /= 2;
            aport *= counter;
            ans += aport;
        }
        counter += x.second;
    }
    cout << ans << endl;
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

// Problem: C. Inhabitant of the Deep Sea
// Contest: Codeforces - Codeforces Round 938 (Div. 3)
// URL: https://codeforces.com/contest/1955/problem/C
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    ull n, k;
    cin >> n >> k;
    vector<ull> arr(n);
    forn
    {
        cin >> arr[i];
    }
    int p1 = 0;
    int p2 = n - 1;
    int first = 1;
    while (k > 0 && p1 < p2)
    {
        ull to_advance = min(k, 2 * min(arr[p1] - 1, arr[p2] - 1));
        if (to_advance > 1)
        {
            to_advance -= to_advance % 2;
            k -= to_advance;
            arr[p1] -= to_advance / 2;
            arr[p2] -= to_advance / 2;
        }
        else if (first)
        {
            arr[p1]--;
            first = 0;
            k--;
            if (arr[p1] == 0)
            {
                p1++;
            }
        }
        else
        {
            arr[p2]--;
            first = 1;
            k--;
            if (arr[p2] == 0)
            {
                p2--;
            }
        }
    }
    if (p1 == p2 && k > 0)
    {
        int rr = min(k, arr[p1]);
        arr[p1] -= rr;
        k -= rr;
    }
    int count = 0;
    forn
    {
        count += (arr[i] == 0);
    }
    cout << count << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
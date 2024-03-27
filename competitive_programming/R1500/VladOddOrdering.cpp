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

void BruteSolve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> A;
    forn
    {
        int e = i + 1;
        int exp = 0;
        while (e > 0 && e % 2 == 0)
        {
            e /= 2;
            exp++;
        }
        A.pb({exp, e});
    }
    sort(A.begin(), A.end());
    forn
    {
        cout << (i + 1) << wp << A[i].first << wp << A[i].second << endl;
    }
    return;
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> A;
    int actual = 0;
    while (n > 0)
    {
        int ceil = n / 2 + (n % 2);
        A.pb(actual + 1);
        n = n / 2;
        actual += ceil;
    }
    // do a binary search on to locate k.
    int st = 0;
    int ed = A.size() - 1;
    while (ed - st > 1)
    {
        int middle = st + (ed - st) / 2;
        if (A[middle] > k)
        {
            ed = middle - 1;
        }
        else
        {
            st = middle;
        }
    }
    if (st + 1 < A.size() && k >= A[st + 1])
    {
        st++;
    }
    int ans = 1;
    for (int i = 0; i < st; i++)
    {
        ans *= 2;
    }
    ans *= 2 * (k - A[st]) + 1;
    cout << ans << endl;
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

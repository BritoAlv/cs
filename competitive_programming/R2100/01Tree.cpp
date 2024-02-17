#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back
#define ull unsigned long long

// je m appelle Alvaro j ai 21 ans.

using namespace std;

int a[200000];
int n;

int comparer(pair<int, int> A, pair<int, int> B)
{
    if (A.first != B.first)
    {
        return A.first > B.first;
    }
    else
    {
        return A.second < B.second;
    }
}

void Solve()
{
    cin >> n;
    int zero_count = 0;
    forn
    {
        cin >> a[i];
        zero_count += (a[i] == 0);
    }
    if (zero_count != 1)
    {
        cout << "NO" << endl;
        return;
    }
    vector<pair<int, int>> A;
    set<pair<int, int>> B;
    forn
    {
        A.pb({a[i], i});
        B.insert({i, a[i]});
    }
    sort(A.begin(), A.end(), comparer);
    for (int i = 0; i < n - 1; i++)
    {
        pair<int, int> to_find = {A[i].second, A[i].first};
        auto x = B.find(to_find);
        auto y = B.upper_bound(to_find);
        int checked = 0;
        if (x != B.begin())
        {
            int num = (*(--x)).second;
            if (num == to_find.second || num == to_find.second - 1)
            {
                checked = 1;
            }
        }

        if (y != B.end())
        {
            int num = (*y).second;
            if (num == to_find.second || num == to_find.second - 1)
            {
                checked = 1;
            }
        }
        B.erase(B.find(to_find));
        if (!checked)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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

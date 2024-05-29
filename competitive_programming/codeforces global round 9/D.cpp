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

int compute_mex(vector<int> a)
{
    set<int> vv;
    for (auto x : a)
    {
        vv.insert(x);
    }
    int mexx = 0;
    for (auto x : vv)
    {
        if (x != mexx)
        {
            return mexx;
        }
        else
        {
            mexx++;
        }
    }
    return mexx;
}

int is_sorted(vector<int> &a)
{
    int r = 1;
    for (int i = 1; i < a.sz; i++)
    {
        r &= (a[i] >= a[i - 1]);
    }
    return r;
}

void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    forn
    {
        cin >> a[i];
    }
    int ops = 0;
    vector<int> index;
    while (!is_sorted(a))
    {
        int mex = compute_mex(a);
        if (mex == n)
        {
            int minn = -1;
            forn
            {
                if (a[i] != i)
                {
                    minn = i;
                    break;
                }
            }
            a[minn] = n;
            ops++;
            index.pb(minn + 1);
        }
        else
        {
            a[mex] = mex;
            ops++;
            index.pb(mex + 1);
        }
    }
    cout << index.sz << endl;
    for (auto x : index)
    {
        cout << x << wp;
    }
    cout << endl;
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

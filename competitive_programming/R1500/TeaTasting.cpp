// Problem: C. Tea Tasting
// Contest: Codeforces - Educational Codeforces Round 143 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1795/C
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

int count_g(int x, vector<int> &l)
{
    // count how many lis are > x.
    if (l.size() == 0 || l.back() <= x)
    {
        return 0;
    }
    int st = 0;
    int ed = l.size() - 1;
    while (ed - st > 1)
    {
        int md = st + (ed - st) / 2;
        if (l[md] > x)
        {
            ed = md;
        }
        else
        {
            st = md + 1;
        }
    }
    while (l[st] <= x)
    {
        st++;
    }
    return l.size() - st;
}

int count_l(int x, vector<int> &l)
{
    // count how many lis are < x.
    if (l.size() == 0 || l[0] >= x)
    {
        return 0;
    }
    int st = 0;
    int ed = l.size() - 1;
    while (ed - st > 1)
    {
        int md = st + (ed - st) / 2;
        if (l[md] < x)
        {
            st = md;
        }
        else
        {
            ed = md - 1;
        }
    }
    while (l[ed] >= x)
    {
        ed--;
    }
    return ed + 1;
}

int count_segments(int x, vector<int> &l, vector<int> &r)
{
    int n = l.size();
    // count for how many segments l[i] > x
    return n - count_g(x, l) - count_l(x, r);
}

ull a[200000];
ull b[200000];

ull psum(int l, int r)
{
    return b[r] - (l > 0 ? b[l - 1] : 0);
}

void Solve()
{
    int n;
    cin >> n;
    forn
    {
        cin >> a[i];
    }
    int bb[n];
    forn
    {
        cin >> b[i];
        bb[i] = b[i];
        if (i > 0)
        {
            b[i] += b[i - 1];
        }
    }
    vector<int> l;
    vector<int> r;
    vector<ull> c(n, 0);
    forn
    {
        if (a[i] > psum(i, n - 1))
        {
            l.pb(i);
            r.pb(n - 1);
        }
        else
        {
            int st = i;
            int ed = n - 1;
            while (ed - st > 1)
            {
                int md = st + (ed - st) / 2;
                if (a[i] <= psum(i, md))
                {
                    ed = md;
                }
                else
                {
                    st = md + 1;
                }
            }
            while (a[i] > psum(i, st))
            {
                st++;
            }
            int j = st;

            if (j != i)
            {
                l.pb(i);
                r.pb(j - 1);
                c[j] += a[i] - psum(i, j - 1);
            }
            else
            {
                c[j] += a[i];
            }
        }
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    forn
    {
        cout << c[i] + (ull)bb[i] * count_segments(i, l, r) << wp;
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
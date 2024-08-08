// Problem: C. Turtle and an Incomplete Sequence
// Contest: Codeforces - Codeforces Round 949 (Div. 2)
// URL: https://codeforces.com/contest/1981/problem/C#
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
#define pi pair<long long, long long>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

long long a[200000];

void ss(int l, int r)
{
    int x = a[l];
    int y = a[r];
    set<int, greater<int>> part1;
    part1.insert(x);
    set<int> part2;
    part2.insert(y);
    while (x >= 1)
    {
        part1.insert(x);
        x /= 2;
    }
    while (y >= 1)
    {
        part2.insert(y);
        y /= 2;
    }
    for (auto z : part1)
    {
        if (part2.find(z) != part2.end())
        {
            int lca = z;
            // cout << lca << endl;
            int i = l + 1;
            part1.erase(a[l]);
            while (i < r && part1.sz > 0 && *part1.begin() > lca)
            {
                a[i] = *part1.begin();
                part1.erase(part1.begin());
                i++;
            }
            auto pt = part2.find(lca);
            if (lca == a[l])
            {
                pt++;
            }
            while (i < r && pt != part2.end() && *pt != a[r])
            {
                a[i] = *pt;
                pt++;
                i++;
            }
            int flag = 1;
            while (i < r)
            {
                if (flag)
                {
                    a[i] = 2 * a[i - 1];
                }
                else
                {
                    a[i] = a[i - 1] / 2;
                }
                flag = !flag;
                i++;
            }
            break;
        }
    }
}

void Solve()
{
    int n;
    cin >> n;
    forn
    {
        cin >> a[i];
    }
    forn
    {
        if (a[i] == -1)
        {
            int ed = i;
            while (ed + 1 < n && a[ed + 1] == -1)
            {
                ed++;
            }
            if (i == 0)
            {
                long long st = (ed == n - 1 ? 1 : a[ed + 1]);
                int f = 0;
                for (int j = ed; j >= 0; j--)
                {
                    f = !f;
                    if (f)
                    {
                        a[j] = 2 * st;
                    }
                    else
                    {
                        a[j] = st / 2;
                    }
                    st = a[j];
                }
            }
            else if (ed == n - 1)
            {
                long long st = a[i - 1];
                int f = 0;
                for (int j = i; j <= ed; j++)
                {
                    f = !f;
                    if (f)
                    {
                        a[j] = 2 * st;
                    }
                    else
                    {
                        a[j] = st / 2;
                    }
                    st = a[j];
                }
            }
            else
            {
                ss(i - 1, ed + 1);
            }
            i = ed;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != a[i + 1] / 2 && a[i] / 2 != a[i + 1])
        {
            cout << -1 << endl;
            return;
        }
    }
    forn
    {
        cout << a[i] << wp;
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
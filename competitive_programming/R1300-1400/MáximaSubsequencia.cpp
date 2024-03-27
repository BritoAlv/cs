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

int fp(int s, vector<int> &pos)
{
    if (pos.back() < s)
    {
        return -1;
    }
    int st = 0;
    int ed = pos.size() - 1;
    while (ed - st > 1)
    {
        int middle = st + (ed - st) / 2;
        if (pos[middle] >= s)
        {
            ed = middle;
        }
        else
        {
            st = middle + 1;
        }
    }
    while (pos[st] < s)
    {
        st++;
    }
    return pos[st];
}

int lp(int s, vector<int> &pos)
{
    if (pos[0] > s)
    {
        return -1;
    }
    int st = 0;
    int ed = pos.size() - 1;
    while (ed - st > 1)
    {
        int middle = st + (ed - st) / 2;
        if (pos[middle] <= s)
        {
            st = middle;
        }
        else
        {
            ed = middle - 1;
        }
    }
    while (pos[ed] > s)
    {
        ed--;
    }
    return pos[ed];
}

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    map<int, vector<int>> pos;
    forn
    {
        cin >> a[i];
        if (pos.find(a[i]) == pos.end())
        {
            pos[a[i]] = vector<int>();
        }
        pos[a[i]].pb(i);
    }
    int lg[n];
    int sg[n];
    sg[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (pos.find(a[i] - 1) == pos.end())
        {
            sg[i] = 1;
        }
        else
        {
            int next = lp(i - 1, pos[a[i] - 1]);
            if (next == -1)
            {
                sg[i] = 1;
            }
            else
            {
                sg[i] = 1 + sg[next];
            }
        }
    }
    lg[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (pos.find(a[i] + 1) == pos.end())
        {
            lg[i] = 1;
        }
        else
        {
            int next = fp(i + 1, pos[a[i] + 1]);
            if (next == -1)
            {
                lg[i] = 1;
            }
            else
            {
                lg[i] = 1 + lg[next];
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, lg[i] + 1);
        if (pos.find(a[i] + 2) != pos.end())
        {
            int next = fp(i + 1, pos[a[i] + 2]);
            if (next != -1)
            {
                ans = max(ans, sg[i] + 1 + lg[next]);
            }
        }
    }
    cout << ans << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
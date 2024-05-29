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

int rem[1000];
int n;
vector<int> chosen(vector<set<pi>> &rem, int to_find)
{
    vector<vector<int>> sequences(n, vector<int>());
    for (auto x : rem[0])
    {
        if (sequences[x.second].sz == 0)
        {
            sequences[x.second].pb(x.first);
        }
    }
    for (int i = 1; i < rem.sz; i++) // O(n)
    {
        vector<vector<int>> updated(n, vector<int>());
        for (auto y : rem[i]) // O(10)
        {
            for (int j = 0; j < n; j++) // O(n)
            {
                if (sequences[j].sz > 0 && updated[(y.second + j) % n].sz == 0)
                {
                    updated[(y.second + j) % n] = sequences[j];
                    updated[(y.second + j) % n].pb(y.first);
                }
            }
        }
        sequences = updated;
    }
    return sequences[to_find];
}

void Solve()
{
    string s;
    cin >> s >> n;
    if (n == 1)
    {
        for (int i = 0; i < 1000; i++)
        {
            rem[i] = 0;
        }
    }
    else
    {
        rem[0] = 1;
        for (int i = 1; i < 1000; i++)
        {
            rem[i] = (rem[i - 1] * 10) % n;
        }
    }
    vector<set<pi>> rems;
    int to_find = 0;
    for (int exp = 0; exp < s.sz; exp++)
    {
        if (s[s.sz - 1 - exp] == '?')
        {
            set<pi> sett;
            if (s.sz - 1 != exp)
            {
                sett.insert({0, 0});
            }
            for (int i = 1; i <= 9; i++)
            {
                sett.insert({i, (rem[exp] * i) % n});
            }
            rems.pb(sett);
        }
        else
        {
            to_find += ((s[s.sz - 1 - exp] - '0') * rem[exp]) % n;
            to_find %= n;
        }
    }
    to_find = (n - to_find) % n;
    if (rems.sz == 0)
    {
        cout << "*" << endl;
    }
    auto result = chosen(rems, to_find);
    if (result.sz != rems.sz)
    {
        cout << "*" << endl;
    }
    else
    {
        stack<int> t;

        for (auto x : result)
        {
            t.push(x);
        }
        for (int i = 0; i < s.sz; i++)
        {
            if (s[i] == '?')
            {
                cout << t.top();
                t.pop();
            }
            else
            {
                cout << s[i];
            }
        }
        cout << endl;
    }
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
